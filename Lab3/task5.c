//Grace Burton
//COSC350
//Lab 3 Task 5

#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <stdio.h>

//Writes a simple c code to open file (foo) as input and write into
//file (foorev) using by using lseek system call (foorev permissions rwxrw--)

#define FILE_MODE (S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP)

//error thrown template
void err_sys(char* str){

	printf("%s", str);
	exit(1);
}

int main(int argc, char* argv[]){

	//using curr to keep track of bytes 
	int infile, outfile, curr;
	char buf;

	infile = open("foo", O_RDONLY);
	if(infile < 0){
		err_sys("Read infile error");
	}

	umask(0);

	outfile = creat("foorev", FILE_MODE);
	if(outfile < 0){
		err_sys("Creating file error");
	}

	curr = lseek(infile, -1, SEEK_END);
	if(curr == -1){
		err_sys("Create lseek error");
	}

	for(; curr >= 0; curr--){

		read(infile, &buf, 1);
		write(outfile, &buf, 1);
		lseek(infile, -2, SEEK_CUR);
	}

	close(infile);
	close(outfile);

	exit(0);
}
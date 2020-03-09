//Grace Burton
//COSC350
//Lab 3 Task 6

#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>

//Writes a simple c code to open file (foo) as input and write into
//file (foorev) using by using pread system call (foorev permissions rwxrw--)

#define FILE_MODE (S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP)

//error thrown template
void err_sys(char* str){

	printf("%s", str);
	exit(1);
}

int main(int argc, char* argv[]){

	//using curr to keep track of bytes for system call
	//nbytes keeps track of pread bytes recorded
	int infile, outfile, temp;
	char buf;

	infile = open("foo", O_RDONLY);
	if(infile < 0){

		err_sys("Open infile error");
	}

	umask(0);

	outfile = open("foorev", O_WRONLY|O_CREAT|O_EXCL, FILE_MODE);

	if(outfile < 0){

		err_sys("Creating file error");
	}

	temp = 0;
	while(read(infile, &buf, 1) == 1){

		temp++;
	}

	while(temp > 0){

		pread(infile, &buf, 1, temp - 1);
		write(outfile, &buf, 1);
		temp--;
	}

	// write(outfile, &buf, 1);

	close(infile);
	close(outfile);

	exit(0);
}
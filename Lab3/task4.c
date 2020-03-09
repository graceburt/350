//Grace Burton
//COSC350
//Lab 3 Task 4

#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <stdio.h>

//Writes a simple c code to open 2 files (foo1, foo2) & append to file (foo12)
//by using lseek system call (foo12 permissions rwxrw--)

#define FILE_MODE (S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP)

//error thrown template
void err_sys(char* str){

	printf("%s", str);
	exit(1);
}

int main(){

	int infile1, infile2, outfile;
	int nbyte;
	char buf1;
	char buf2;

	//Opening the file "foo" for read only by owner, or rw-------
	infile1 = open("foo1", O_RDONLY);
	infile2 = open("foo2", O_RDONLY);

	if(infile1 < 0 || infile2 < 0){
		err_sys("Input file error");
	}

	//clears mask to 0
	umask(0);

	//creates the file foo12 with the mode defined above
	if((outfile = creat("foo12", FILE_MODE)) < 0){
		err_sys("Create new file error");
	}

	// Copys contents of "foo1" byte by byte to "foo12"
	while((read(infile1, &buf1, 1) == 1)){
		write(outfile, &buf1, 1);
	}

	// Copys contents of "foo2" byte by byte to "foo12"
	while(read(infile2, &buf2, 1) == 1){
		write(outfile, &buf2, 1);
	}

	close(infile1);
	close(infile2);
	close(outfile);

	exit(0);
}


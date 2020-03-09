//Grace Burton
//COSC350
//Lab 3 Task 2

#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
//Writes a c code to copy content of any readable file (foo) to clone (foo1)
//with open input file. Output will be rw-rw-rw. Read byte by byte
#define FILE_MODE (S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP)
//error thrown template
void err_sys(char* str){

	printf("%s", str);
	exit(1);
}

int main(){

	int infile, outfile;
	char buf;

	//Opening the file "foo" for read only by owner, or rw-------
	infile = open("foo", O_RDONLY);
	if(infile < 0){

		err_sys("Input file error");
	}
	
	//clears mask to 0
	umask(0);

	//Opening the file "clone1" --since not created, will create using O_CREAT
	//with permissions rw-rw-rw
	if(outfile = creat("foorev", FILE_MODE) < 0){

		err_sys("Create file error");
	}

	//while reading infile "foo" does not run out of buffer space
	while(read(infile, &buf, 1) == 1){

		//write the buffer recorded by read into outfile "clone1"
		write(outfile, &buf, 1);
	}

	close(infile);
	close(outfile);

	exit(0);

}
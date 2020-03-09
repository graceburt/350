//Grace Burton
//COSC350
//Lab 3 Task 3

#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>

//Writes a c code to copy content of any readable file (foo) to clone (foo1)
//with open input file. Use 32 byte buffer. Output will be rwx-rwx---.
#define BUFFER_SIZE 32

//error thrown template
void err_sys(char* str){

	printf("%s", str);
	exit(1);
}

int main(){

	int infile, outfile, nbyte;
	char buf[BUFFER_SIZE];

	//**Solved bug: Keep file opening outside of if statement

	//Opening the file "foo" for read only by owner, or rw-------
	infile = open("foo", O_RDONLY);
	if(infile < 0){

		err_sys("Input file error");
	}

	//clears mask to 0
	umask(0);

	//**Solved bug: Keep file opening outside of if statement

	//Opening the file "clone2" --since not created, will create using O_CREAT
	//with permissions rwx-rwx---

	outfile = open("clone2", O_WRONLY|O_CREAT|O_EXCL, 0770);

	if(outfile < 0)
	{
		err_sys("Output file error.");

	}

	//**Solved bug: didn't but the nbyte = read line into paratheses, so 
	//it was only reading the first bit into the new file "clone2"

	//while reading infile "foo" does not run out of buffer space
	while((nbyte = read(infile, buf, BUFFER_SIZE)) > 0){

		write(outfile, buf, nbyte);
		//write the buffer recorded by read into outfile "clone2"
	}

	if(nbyte < 0){
				err_sys("Read error");
			}

	close(infile);
	close(outfile);

	exit(0);

}
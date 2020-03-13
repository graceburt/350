// Write a C program which accepts two file names as arguments: input file name and output file name. 
// Your program copies one file to another file. Exit the program with an appropriate error message under the following error conditions:
//If input file is not available

#include<unistd.h>
#include<cytpe.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char* argv[]){

	int infile, outfile;

	//Opening the file "foo" for read only by owner, or rw-------
	infile = open(argv[1], O_RDONLY);
	if(infile < 0){

		err_sys("Input file error");
	}
	
	//clears mask to 0
	umask(0);

	//Opening the file "clone1" --since not created, will create using O_CREAT
	//with permissions rw-rw-rw
	outfile = creat(agrv[2], O_WRONLY|O_CREAT|O_EXCL, 0666);
	if(outfile < 0){

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
// Grace Burton
// COSC350
// Lab 3 Task 8

#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <stdio.h>

//Write a c program that passes an input (.txt file) and output file name 
//as command line arguments. Open the infile as read only & outfile as rw-rw-rw
//Your program should encode each character to ASCII code # and writes to output file.
//Consider argument # error and open file error. WRITE OWN INT TO ASCII function

//Basically we want to open a textfile, read the contents & convert to ASCII code number
//then write that to the output file

void err_sys(char* str){

	printf("%s", str);
	exit(1);
}

//convert int -> str

// int int_to_str(int ascii, char* asciibuf, int s){

// 	int i = 0;
// 	int asciizero = 48;

// 	//while there exists a command line input 
// 	//take the number recorded inside the array, find the ASCII value
	
// 	for(i = (s-1); i >= 0; i--){

// 		asciibuf[i] = (ascii%10)+asciizero;
// 		ascii /= 10;
// 	}

// 	return ascii;
// }

int main(int argc, char* argv[]){

	if(argc != 3){
		err_sys("Argument number error!");
	}

	int infile, outfile, num;
	char buf;

	infile = open(argv[1], O_RDONLY);
	if(infile < 0){

		err_sys("Read infile error");
	}

	umask(0);
 
 	outfile = open(argv[2], O_RDWR|O_CREAT|O_EXCL, 0666);

	if(outfile < 0){

		err_sys("Creating file error");
	}

	dup2(outfile, 1);

	while(read(infile, &buf, 1) == 1){

		num = (int) buf;
		printf("%d\n", num);
	}

	close(infile);
	close(outfile);
	
	exit(0);
}
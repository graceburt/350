//Grace Burton
//COSC350
//Lab 3 Task 1

#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>

//Writes a c code to copy content of any readable file (foo) to clone (foo1)
//WITHOUT open input file

//using input and output 0 & 1	

//read() will open file "0" and read the amount of data pointed to by
//buf, then returns the number of bytes read (i.e. size of file)

//write() will attempt to write nbyte bytes from the buffer,
//pointed to by buf, to open file "1"

int main(int argc, char* argv[]){


	int bytes;
	char buf;

	while((bytes = read(0, &buf, 1)) > 0){

		write(1, &buf, bytes);
	}
}
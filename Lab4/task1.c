
// Write a C main function that takes one command-line argument, the name of an input file. The input file contains exactly one integer spread out over a single line of up to 80 characters. 
//For example, the integer 3579 is embedded in the line az3mqrm5t?7!z9v.

// Your program uses system calls to do the following:

//     Open and read the input file, accumulating the discovered digit characters into a character array (string)
//     Convert the string to an integer (do not use atoi function)
//     Add 10 to the integer
//     Convert the sum back to a string (using function convIntToStr)
//     Make a system call to write the string to standard output

#include<unistd.h>
// #include<cytpe.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

// Converts integer number to string,
// and returns the length of the string
int convIntToStr(char * str, int x)
{
    sprintf(str, "%d", x);
    return (strlen(str));
}

// Converts a string to an integer,
// and returns the integer value
int st_to_int(char* str){

	int num = 0;
	int index = 0;

	//while there exists a command line input 
	//take the number recorded inside the array, find the ASCII value
	
	while(str[index] != '\0'){

		num = (num*10)+(str[index]-48);
		index++;
	}

	return num;
}

// Checks if an integer falls in the ascii range of 0 - 9,
// and returns 1 if true, and zero if false
int isdigit(int i)
{
    if(i >= 48 && i <= 57)
        return 1;
    else
        return 0;
}


int main(int argc, char* argv[]){

	//using curr to keep track of bytes 
	int infile, outfile, curr, nr, index;
	char buf[80], nr[80];

	infile = open(argv[1], O_RDONLY);
	if(infile < 0){
		err_sys("Read infile error");
	}

	umask(0);

	outfile = creat(argv[2], O_WRONLY|O_CREAT|O_EXCL, 0666);
	if(outfile < 0){
		err_sys("Creating file error");
	}

	// Reads through the input file,
    // checking every character for if it is a digit,
    // and stores it inside a string if it is a digit
	curr = pread(infile, &buf, sizeof(buf), 0);

	    while(read(infile, &buf, 1) == 1)
        if(isdigit(buf))
        {
            str[i] = buf;
            i++;
        }

    // Converts the string to an integer and adds 10 to it
    int num = myatoi(str);
    num += 10;
    convIntToStr(str, num);

    // Writes the integer to the standard output
    write(1, str, i);  

	while()

}
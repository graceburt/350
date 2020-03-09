// Grace Burton
// COSC350
// Lab 3 Task 7

#include<stdio.h>
#include<stdlib.h>

// write a c program that recieves a series of int from command line
// and prints their sum to the screen. DEFINE OWN ATOI FUNCTION.
// exit with appropriate error under condition there were no integers entered.
// error thrown template

void err_sys(char* str){

	printf("%s", str);
	exit(1);
}

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

int main(int argc, char* argv[]){

	if(argc < 2){
		err_sys("No integers present");
	}

	//Starting index at 1 skips the ./programname in agrv array

	int num;
	int index = 1;
	int total = 0;

	//loops through the arguments by making sure there
	//is one left behind current index to add

	for(; index<=(argc-1); index++){

		num = st_to_int(argv[index]);
		total += num;
	}

	printf("The sum of the command line arguments is: %d\n", total);

	exit(0);
}
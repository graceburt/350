// Grace Burton
// COSC350
// Lab 3 Task 9

#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <stdio.h>

//error thrown template
void err_sys(char* str){

	printf("%s", str);
	exit(1);
}

int palind(int f1, int f2){

	char buf1, buf2;
	int curr;

	//Looking for the beginning of the file
	int size = lseek(f2, -2, SEEK_END);

	if(size == -1){
		err_sys("Create lseek error");
	}

	for(; curr < size; curr++){

		//position offset at the beginning + curr of f1
		lseek(f1, curr, SEEK_SET);

		//read byte by byte
		read(f1, &buf1, 1);

		//position offset at the char before current char
		lseek(f1, -2 - curr, SEEK_END);
		read(f2, &buf2, 1);

		if(buf1 != buf2){
			return 0;
		}
	}
return 1;
}

int main(int argc, char *argv[]){

	if(argc != 2){
		err_sys("Argument number error!\n");
	}

	int fd1, fd2, result;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = dup(fd1);

	if(fd1 < 0 || fd2 < 0)
    {
        err_sys("Input file error.\n");
    }

	result = palind(fd1, fd2);

	if(result == 1){

		printf("The file is a palindrome!\n");
	}
	else{
		printf("The file is NOT a palindrome!\n");
	}

	close(fd1);
	close(fd2);

	exit(0);
}
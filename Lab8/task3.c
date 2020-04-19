// Grace Burton
// COSC350
// Lab 8 Task 3

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//A parent process asks two integers from command line and send to child by using pipe. 
//The child process makes sure the two inputs are integers. 
//The child process calculates the sum of two integer and output on standard output. The child process continue until input from the parent are EOF

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

#define MAXLINE 256

void err_sys(char *str){
	printf("%s \n",str);
	exit (1);
}

int main(){

	int n, fd[2], size, int1, int2;
	pid_t pid;
	char sline[MAXLINE], rline[MAXLINE];

	if (pipe(fd) < 0) {
		err_sys("pipe error");
	}

	if ((pid = fork()) < 0){

		err_sys("fork error");
	}
	else if (pid > 0){

		close(fd[0]); // fd[0] need to be close since fd[1] is used for sending data
		printf("submit two integers\n");

		while( (size = read(STDIN_FILENO, sline, MAXLINE)) > 0) {

			write(fd[1], sline, size); //write to a pipe 
			printf("submit two integers\n");
		}

	}//end elif
	else{ // child use pipe to receive message from the parent 

		close(fd[1]);
		//fd[1] need to be close since fd[0] is used for receiving data
		
		//read from the pipe
		while((n = read(fd[0], rline, MAXLINE)) > 0){

			//chose first two string as two integer
			if(sscanf(rline, "%d%d", &int1, &int2) == 2){

				sprintf(rline, "%d\n", (int1 + int2));
				n = strlen(rline);

				if(write(STDOUT_FILENO, rline, n) != n){
					
					err_sys("write error");
				} 
				else{ //if first two string is not integer
					
					// if(write(STDOUT_FILENO, "invalid args\n", 13) != 13){
					// 	err_sys("write error");
					// }
					//Can't figure out why this is not working, keeps printing "invalid args"
				}//end else 

			}//end if

		} //end while

	}// end else

	return 0;
}
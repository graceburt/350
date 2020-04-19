// Grace Burton
// COSC350
// Lab 7 Task 4

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void SignalHandler(int sig){
	if(sig == SIGUSR1){
		puts("Hi Honey! Anything wrong?");
	}
	else if(sig == SIGUSR2){
		puts("Do you make trouble again?");
	}
}

int main(int argc, char* argv[])
{


	pid_t pid1, pid2;

	pid1 = fork();
	if(pid1 < 0){

		puts("Fork failed.");
		exit(1);
	}
	else if(pid1 == 0){

		kill(pid1, SIGUSR1);
	}
	else{

		pid2 = fork();

		if(pid2 < 0){

			puts("Fork failed.");
			exit(1);
		}
		else if(pid2 == 0){

			kill(pid2, SIGUSR2);
			pause();
		}
		else{
			
			signal(SIGUSR1, SignalHandler);
			signal(SIGUSR2, SignalHandler);
		}
	}

	return 0;
}
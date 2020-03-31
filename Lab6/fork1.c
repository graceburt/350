// Grace Burton
// COSC350
// Lab 6 Task 2

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(){

	if(argc != 4){

		printf("Number of arguments error!")
		exit(1);
	}

	int nc = argv[1];
	int np = argv[2];
	int tc = argv[3];
	int tp = argv[4];

	pid_t pid;
	char* message;
	int n;
	int exit_code;

	printf("fork program starting\n");
	pid = fork();

	switch(pid) {

		case -1:
			perror("fork failed");
			exit(1);
		case 0:
			message = "This is the child";
			n = 5;
			exit_code = 37;
			break;
		default:
			message = "This is the parent";
			n = 3;
			exit_code = 0;
			break;
		}

	for(; n > 0; n--) {

		puts(message);
		sleep(1);
		}

	if(pid != 0){

		int stat_val;
		pid_t child_pid;

		child_pid = wait(&stat_val);

		printf("The child has finished: PID = %d\n", child_pid);
		if( WIFEXITED(stat_val)){
			printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
		}
		else{
			printf("Child terminated abnormally\n");
		}

		exit(exit_code);

		}
	}
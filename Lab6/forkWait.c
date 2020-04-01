// Grace Burton
// COSC350
// Lab 6 Task 3

// Modify forkWait.c
// so the parent process waits for the child to finish

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int myatoi(char *str)
{
	int num = 0;
	int index = 0;

	while(str[index] != '\0')
	{
		num = (num * 10) + (str[index] - 48);
		index++;
	}
	return num;
}

int main(int argc, char *argv[]){

	if(argc != 5){

		printf("Number of arguments error!");
		exit(1);
	}

	int nc = myatoi(argv[1]);
	int np = myatoi(argv[2]);
	int tc = myatoi(argv[3]);
	int tp = myatoi(argv[4]);

	pid_t pid;
	char* message;
	int exit_code, time;
	int n;

	printf("fork program starting\n");
	pid = fork();

//makes parent wait for child process using wait() function
//uses the child's id to identify what program needs to finish
	
	switch(pid) {

		case -1:
			perror("fork failed");
			exit(1);
		case 0 :
			message = "This is the child";
			n = nc;
			time = tc;
			exit_code = 37;
			break;
		default:
			message = "This is the parent";
			n = np;
			time = tp;
			exit_code = 0;
			wait(&pid);
			break;
		}

	for(; n > 0; n--) {

		puts(message);
		sleep(exit_code);

	}

	// if(pid != 0){

	// 	pid_t child_pid;

	// 	child_pid = wait(tc);

	// 	printf("The child has finished: PID = %d\n", child_pid);
	// 	if( WIFEXITED(tc)){
	// 		printf("Child exited with code %d\n", WEXITSTATUS(tc));
	// 	}
	// 	else{
	// 		printf("Child terminated abnormally\n");
	// 	}


	// 	}

}
// Grace Burton
// COSC350
// Lab 6 Task 4

// Modify forkExec.c so the child process image is replaced by the image of a program named child. 
// Use one of the exec family of functions to do this.

// Write child.c to do the same thing as the child process did in Task 4. 
// The child should give its pid each time it prints the message. 
//The parent should give its pid each time it prints the message. 
//The childprogram should take three command-line arguments, the message, Nc, and Tc. 
// To get an interesting exit status from the child, have it return 37, rather than 0


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
	int exit_code;
	int n;

	printf("fork program starting\n");
	pid = fork();

//execlp function - replacing the current process the with a new process.
// in this case, it runs the program "./child" with the command line arguments we pass through the parent function forkExec 

// EXAMPLE of EXECLP:

//Say you run this from a commandline/shell:
// $ ls
// That'd be execlp("ls", "ls", (char *)NULL); Or if you run
// $ ls -l /

	switch(pid) {

		case -1:
			perror("fork failed");
			exit(1);
		case 0 :
			execlp("./child", argv[1], argv[3], "Parent is here", (char*)0);
			break;
		default:
			for(; np > 0; np--)
			{
				printf("Parent ID = %d. \n", getpid());
				sleep(tp);
			}
			break;
		}

	if(pid != 0){

		int stat_val;
		pid_t child_pid;

		child_pid = wait(&stat_val);

		printf("The child has finished: PID = %d\n", child_pid);
			if(WIFEXITED(stat_val)){
				printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
			}
			else{
				printf("Child terminated abnormally\n");
			}


		}

	exit(exit_code);

	}
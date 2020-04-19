// Grace Burton
// COSC350
// Lab 6 Task 2

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

//Has parent and child process running, depending on value of nc (child process iterations)
//and np (parent process iteration), is the amount each are printed out. tc is time for child to wait and tp is time for parent to wait.
//run simultaneously! Just wait with time assigned (using sleep() not wait()!)

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
	int time;
	int n;

	printf("fork program starting\n");
	pid = fork();

	switch(pid) {

		case -1:
			perror("fork failed");
			exit(1);
		case 0 :
			message = "This is the child";
			n = nc;
			time = tc;
			break;
		default:
			message = "This is the parent";
			n = np;
			time = tp;
			break;
		}

	for(; n > 0; n--) {

		puts(message);
		sleep(time);

	}

	exit(0);

	}
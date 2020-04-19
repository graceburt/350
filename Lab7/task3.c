// Grace Burton
// COSC350
// Lab 7 Task 2

#include <sys/types.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){


	pid_t pid;
	int childfile, infile;

	char buf1[] = "Hi, Mom";
	char buf2;

	pid = fork();

	switch(pid) {

		case -1:
			perror("fork failed\n");
			exit(1);

		case 0 :
			
			printf("This is the child\n");

			//clears mask to 0
			umask(0);

			childfile = open("foo", O_WRONLY|O_CREAT|O_EXCL, 0666);

			write(childfile, &buf1, strlen(buf1));

			break;

		default:

			printf("\nThis is the parent\n");
			
			wait(&pid);

			infile = open("foo", O_RDONLY);

			printf("My son said, ");
			
			//while reading infile "foo" does not run out of buffer space
			while(read(infile, &buf2, 1) > 0){

				//print child's buff to the console
				printf("%c", buf2);
			}

			break;
		}

	close(childfile);
	close(infile);

	exit(0);

}
// Grace Burton
// COSC350
// Lab 7 Task 2

//ctrl1.c

//Typing Ctrl+C for the first time causes the program to react and then continue. 
//When you type Ctrl+C again, the program ends because the behavior of SIGINThasreturned to the default behavior of causing the program to exit

#include <signal.h>
#include <stdio.h>
#include <unistd.h>

			// void ouch(int sig){
			// 	printf("\nOUCH! - I got signal %d\n", sig);
			// 	(void) signal(SIGINT, SIG_DFL);
			// }

			// int main(){
				
			// 	(void) signal(SIGINT, ouch);

			// 	while(1) {
			// 		printf("Hello World!\n");
			// 		sleep(1);
			// 	}

			// }

//ctrl2.c

// When you run this version of the program, you always get a message when you type Ctrl+C 
// because SIGINT is handled repeatedly by sigaction. 
// To terminate the program, you have to type Ctrl+\, which generates the SIGQUIT signal by default.

void ouch(int sig){
		printf("\nOUCH! - I got signal %d\n", sig);
		(void) signal(SIGINT, SIG_DFL);
	}

int main(){

	struct sigaction act;

	act.sa_handler = ouch; //the SIG handler function
	sigemptyset(&act.sa_mask); //clear the default sig -- so no return to ctrl+c quit!!!
	act.sa_flags = 0; //again, default

	sigaction(SIGINT, &act, 0);

	while(1) {
		printf("Hello World!\n");
		sleep(1);
		}

}

//When using the kill() command on a child program, it will cut off the program instead of letting it run forever,
//which is the original behavior before returning the ctrl+c command to default (in the final program)


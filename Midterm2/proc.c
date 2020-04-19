//process examples
//slides 14

	//zombie.c shows zombie process
	
	//wait.c has parent process wait till child finishes printing 100 times

	//execex.c shows child calling another program

// -------------------------------------------------

// /* zombie.c: create a zombie process */
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <sys/types.h>

// int main(void){
	
// 	int pid; 
// 	pid = fork(); 

// 	 parent sleeps 100 sec 
// 	if(pid > 0){

// 		sleep(100); 
// 	} 
// 	/* a child terminate parent don't have time to save a child info */
// 	/* child remains as a zombie */
// 	else{   

// 		exit(0); 
// 	}
// }

// /*wait.c  demonstrate wait() system call */

// #include <stdio.h>
// #include <string.h>
// #include <sys/wait.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <sys/types.h>

// #define MAX_COUNT 100
// #define BUF_SIZE 100

// void main(void){  
	
// 	pid_t   pid1, pid, p1;
// 	int status;
// 	int i;
// 	char buf[BUF_SIZE];

// 	printf("*** Parent is about to fork  ***\n");
	
// 	if((pid1 = fork()) < 0) {

// 		printf("Failed to fork process 1\n");
// 		exit(1);

// 	}else if(pid1 == 0) /* child's part */{

// 		p1 = getpid();

// 		for(i = 1; i < MAX_COUNT; i++){  

// 			sprintf(buf,"child %d is running\n", p1);
// 			write(1, buf, strlen(buf));
// 		}

// 		_exit(0);
// 	}else /* parent's part */{

// 		sprintf(buf, "*** Parent enters waiting status .....\n");
// 		write(1, buf, strlen(buf));
// 		pid = wait(&status); /*wait for child finish it's job */

// 			if(WIFEXITED(status)){
// 				printf(" A child process terminate normally\n");
// 			}
// 			else{
// 				printf(" A child process terminate abnormally\n");
// 			}

// 		sprintf(buf, "*** Parent detects process %d was done ***\n", pid);
// 		write(1, buf, strlen(buf));
// 		printf("*** Parent exits ***\n");
// 		exit(0);
// 	}//end of outside else
// }

// /* execex.c shows execv system call */

// #include <stdio.h>
// #include <string.h>
// #include <sys/types.h>
// #include <stdlib.h>

// int main (int argc, const char* argv[]){

// 	pid_t pid;
// 	int mult = 1, i;

// 	if(argc == 1){    
// 		printf("argument error \n");
// 		exit (1);
// 	}

// 	if( (pid = fork()) < 0)  /* create child */{

// 		printf("fork error\n");
// 		exit (1);
// 	}else if(pid == 0){   /* a child execute different program */

// 		if(execv ("/home/grace/Documents/COSC350/Midterm2/allocex", argv) < 0){

// 			printf ("execl ERROR");
// 			exit (1);
// 		}
// 	}

// 	for(i = 1; i < argc; i++){

// 		mult *= atoi(argv[i]);
// 	}       

// 	printf ("The multiplication of arguments is %d \n", mult);

// 	exit (0);

// }
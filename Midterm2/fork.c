//environment variable examples
//slides 13

	//fork.c - makes parent & child processes run 1000 lines, runs at same time

	//fork2.c - parent executes 15 times, then child starts executing till both hit 200 - cuz parent runs first

	//fileshare.c - child opens cmd line file and reads into child.txt, then sends to parent to print to parent.txt

	//race.c - shows race condition between parent and child

// -------------------------------------------------

/* fork.c demonstrate fork() system call */

// #include <stdio.h>
// #include <sys/types.h>

// #define MAX_COUNT 10000

// void ChildProcess(); /* child process prototype  */
// void ParentProcess(); /* parent process prototype */

// void main(void){
	
// 	pid_t  pid, ppid;
// 	ppid = getpid(); 
// 	/* get parent process ID */
	
// 	pid = fork(); 
// 	/* create a child */
// 	if(pid == 0){ /* means a child process*/
// 		ChildProcess();
// 	}
// 	else{
// 		ParentProcess();
// 	}

// }
// 	void ChildProcess(){
// 		int i;
// 		for(i = 1; i <= MAX_COUNT; i++){
// 			printf("This line is from child process value = %d\n", i);
// 		}
// 		printf("   *** Child process is done ***\n");

// 	}

// 	void ParentProcess(){
// 		int i;
// 		for(i = 1; i <= MAX_COUNT; i++){
// 			printf("This line is from parent process value = %d\n", i);
// 		}	
// 		printf("*** Parent is done ***\n");

// 	}

// /* fork2.c */
// #include <stdio.h>
// #include <string.h>
// #include <sys/types.h>

// #define MAX_COUNT 200
// #define BUF_SIZE 100

// int main(void){

// 	pid_t  pid, ppid;
// 	int i;
// 	char buf[BUF_SIZE];
// 	ppid = getpid(); 
// 	/* this is parent process ID */
// 	fork(); 
// 	/*create a child */
// 	for(i = 1; i <= MAX_COUNT; i++) {
// 		pid = getpid();
// 		if(pid == ppid){ /* parent works here */
// 			sprintf(buf, "Parent(%d) process executed %d times\n", ppid, i);
// 			write(1, buf, strlen(buf));
// 		}
// 		else{ /* child work here */
// 			sprintf(buf, "Child(%d) process executed %d times\n", pid, i);
// 			write(1, buf, strlen(buf));
// 		}
// 	} 
// 	return 0;
// }

// //fileshare1.c

// #include <unistd.h>
// #include <fcntl.h>
// #include <ctype.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/stat.h>

// void error_sys(char* msg){

// 	printf("%s\n", msg);
// 	exit(1);
// 	}

// int main(int argc, char* argv[]){
	
// 	int input, chout, nbyte, pout;
// 	int i;
// 	char buff[1];

// 	if(argc!= 2){
// 		error_sys("usage: Argument number error\n");
// 	}

// 	input = open(argv[1], O_RDONLY);
// 	pid_t pid;
// 	pid = fork(); /* create a child */

// 	if(pid == 0){ /* child process */

// 		if((chout = open("child.txt", O_WRONLY|O_CREAT, S_IREAD|S_IWRITE)) == -1){
// 			error_sys("Output File Create Error");
// 		}

// 		while((nbyte = read(input, buff, 1)) > 0){
			
// 			if(write(chout, buff, 1) != 1){
// 				error_sys("Write Error");
// 			}
// 		}
// 	}
// 	else{/* parent */

// 		if((pout = open("parent.txt", O_WRONLY|O_CREAT, S_IREAD|S_IWRITE)) == -1){

// 			error_sys("Output File Create Error");
// 		}

// 		while((nbyte= read(input, buff, 1)) > 0){

// 			if(write(pout, buff, 1) != 1)
// 				error_sys("Write Error");
// 		}
// 	}

// 	return 0;
// }




// /*race.c : shows example of race condition*/
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/types.h>

// static void charatatime(char*);

// int main(){
// 	pid_t pid; /* create a child */
// 	if( (pid = fork()) < 0){
// 		printf("fork error");
// 		exit (1);
// 	}
// 	/* a child and parent call same function */

// 	if(pid == 0){
// 		charatatime("output from child\n");
// 	}
// 	else{
// 		charatatime("output from parent\n");
// 	}
// 	exit(0);
// }

// static void charatatime(char*str){
// 	char* ptr; /* child and parent has its own buffer but using same stdout*/
// 	int c;
// 	setbuf(stdout, NULL); /*set unbuffered */
// 	for(ptr = str; c = *ptr++;){
// 		//prints one char at a time to cmd line
// 		putc(c, stdout);
// 	}
// }

// Grace Burton
// COSC350
// Lab 8 Task 4

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

//popen() create a child and pipe. 
//A parent process asks two arguments from command line: a shell command and a file name. 
//then send to child by using popen. Child process will implement the command with file as an input then sent to parent. 
//Parent simply display output from the child on standard output.

int main(int argc, char* argv[]){

	int i;
    int size = 0;
    char *cmd;

    //what is the size of buf
    for(i = 1; i < argc; i++)
    {
        size += strlen(argv[i]);
    }

    //create command from buf
    cmd = calloc(size, sizeof(char));

    for(i = 1; i < argc; i++)
    {
        sprintf(cmd, "%s %s", cmd, argv[i]);
    }

    char buf[BUFSIZ];
    FILE *ptr;
   	
   	//send command to stdin 
    if ((ptr = popen(cmd, "r")) != NULL)
    {
        while (fgets(buf, BUFSIZ, ptr) != NULL)
        {
            (void) printf("%s", buf);
        }
    }

    pclose(ptr);

    return 0;
	
}
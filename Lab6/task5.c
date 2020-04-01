// Grace Burton
// COSC350
// Lab 6 Task 5

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// Write a C program such that receives an input file name as an argument and open the file as inputs. 
// And then create a child process. Input file must open only ONE time and the file descriptor is SHARED by parent and child process.
// Both the parent and the child read a byte at a time from the input file and write output to independent files (parent.txt for parent output, child.txt for child output).
// The parent process collect numeric characters and child collect non-numeric characters. 
// Without any form of synchronization, parent and child process will create wrong output files.

// Do not open the input file twice for synchronization. 
// Define your own function to check numeric character. 
// Do not use vfork(), sleep(), wait() or waitpid() for synchronization.
// Check all possible errors for system calls

int isdigit(int c)
{
    if(c >= 48 && c <= 57)
        return 1;
    else
        return 0;
}

int main(int argc, char* argv[])
{
    pid_t pid;
    int infile, childOut, parentOut, exit_code;
    char buf;
    int childOff = 0;
    int parentOff = 0;

    infile = open(argv[1], O_RDONLY);
    if(infile < 0)
    {
        puts("Input file error.");
		exit(1);
    }

    //output files for parent process & child process
    parentOut = open("parent.txt", O_WRONLY|O_CREAT|O_EXCL, 0755);
    childOut = open("child.txt", O_WRONLY|O_CREAT|O_EXCL, 0755);

    if(childOut < 0 || parentOut < 0)
    {
        puts("Output file error.");
		exit(1);
    }

    pid = fork();

        switch(pid)
        {
            case -1:
                perror("Fork failed.");
                exit(1);
            case 0:
                exit_code = 37;

                //read infile file in
                while(pread(infile, &buf, 1, childOff) == 1)
                {
                	//if there is NOT a digit, write to child output file
	                if(isdigit(buf) == 0)
	                {
	                    write(childOut, &buf, 1);
	                }

                childOff++;
            }
                break;
            default:
                exit_code = 0;

                //read infile
                while(pread(infile, &buf, 1, parentOff) == 1)
                {
                	//if digit, write to parent outfile
	                if(isdigit(buf) == 1)
	                {
	                    write(parentOut, &buf, 1);
	                }
                parentOff++;
            }
                break;
        }

    close(infile);
    close(childOut);
    close(parentOut);

    if(pid != 0)
    {
        int stat_val;
        pid_t child_pid;

        child_pid = wait(&stat_val);

        printf("Child  has finished: PID = %d. \n", child_pid);
        if(WIFEXITED(stat_val))
        {
            printf("Child exited with code %d. \n", WEXITSTATUS(stat_val));
        }
        else
        {
            printf("Child terminated abnormally. \n");
        }
    }
    exit(exit_code);
}
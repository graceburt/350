// Grace Burton
// COSC350
// Lab 5 Task 5.2.1-.2.2

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <utmp.h>

void err_sys(char* str){

	printf("%s", str);
	exit(1);
}

struct tm{

	int sec; //0-60
	int min; //0-59
	int hour; //0 -23
	int day; //1-31
	int mont; //1-12
	int year; //1900 - 2020
	int weekd; //1 - 7
	int yeard; //0 - 365
	int isdst; //y or n

}

//Task 5.2.1 Open utmp file

//Opens utmp file and return filedes
//if cannot be opened, prints error message and exits
int openUtmpFile(){

	filedes = open("var/run/utmp", O_RDONLY);

	if(files < 0){

		err_sys("File cannot be opened");
	}

	return filedes;
}

//Task 5.2.2 Read records from utmp file
int main(){

	umask(0);

	struct utmp *buf;
    int count = 0;
    int filedes = openUtmpFile();
    printf("The utmp file descriptor is %d.\n", filedes);

    // getutent - Reads a line from the current utmp file
    buf = getutent();

 	while(buf != NULL)
    {
        printf("%s \n", buf->ut_user);

        if(buf -> ut_type == USER_PROCESS)
        {
            count ++;
        }
        buf = getutent();

    }

    printf("The number of user processes is %d. \n", count);

    // endutent - closes the utmp file
    endutent();

	exit(0);
}

#include <sys/types.h>
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

int main(int argc, char* argv[])
{
	int nc = myatoi(argv[0]);
	int tc = myatoi(argv[1]);

	for(; nc > 0; nc--)
    {
        printf("Child PID = %d \t %s \n", getpid(), argv[2]);
        sleep(tc);
    }
	exit(37);
}
// Write a simple program called hello.c and compile it and create executable file named hello.

// Write a C program for sequence of following tasks
	
#include<unistd.h>
#include<cytpe.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<dirent.h>

//error thrown template
void err_sys(char* str){

	printf("%s", str);
	exit(1);
}

int main(){
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    char home[] = "/mnt/linuxlab/home/gburton5/";
    char location[256];
    chdir(home);

    sprintf(location, "%s/Dir1", home);
    mkdir(location, 0755);

    sprintf(location, "%s/Dir2", home);
    mkdir(location, 0755);

    sprintf(location, "%s/Dir21", location);
    mkdir(location, 0755);

    sprintf(location, "%s/hello", location);

    char buf;
    int fd1, fd2;

    fd1 = open("hello", O_RDONLY);
    fd2 = open(location, O_CREAT | O_WRONLY, 0775);
    while(read(fd1, &buf, 1) > 0)
    {
        write(fd2, &buf, 0);
    }

    char linkLocation[256];

    sprintf(location, "%s/Dir1/toDir21", home);
    sprintf(linkLocation, "%s/Dir2/Dir21", home);

    symlink(location, linkLocation);

    sprintf(location, "%s/Dir1/toHello", home);
    sprintf(linkLocation, "%s/Dir2/Dir21/hello", home);

    symlink(location, linkLocation);

    close(fd1);
    close(fd2);
    return 0;
}
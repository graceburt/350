// By using bash command mv, you can move a file from current directory to another directory. 
// Write your own mv called MyMv by using system calls link() and unlink(). 
// Your program named MyMv can move a file from a current directory to a directory. 
// Your program receives two arguments: file name and path to a directory where the file needs to be move, or file name and path to directory with a file name.

// If the second argument is a directory, move a file to the directory. If the second argument is not a directory, move file to a directory as a file name.

#include<unistd.h>
#include<cytpe.h>
#include<fcntl.h>
#include<stdlib.h>
#include<stdio.h>
#include<dirent.h>
#include<limits.h>

int MyMv(int argc, char* argv[]){

	//statbuf_src is original file's destination 
	//statbuf_dest is new file's destination
  struct stat statbuf_src;

  umask(0);

  if (argc != 3) {

    printf("%s src dest\n", str[0]);
    exit(1);
  }

  stat(argv[2], &statbuf_src);

  //if argv 2 is a dir then move the file to the directory
  //if not directory, move file to directory as file name
  if(S_ISDIR()){
  	char path[str(argv[2]) + str(argv[1])];
  	//curr path
  	sprintf(path, "%s", path, argv[2]);
  	printf("%s /n", path);
  	//dir above curr path
  	sprintf(path, "%s%s", path, argv[1]);
  	printf("%s /n", path);
  }
  else{

  	char path[str(argv[2]) + str(argv[1])];
  	sprintf(path, "%s", path, argv[2]);
  	printf("%s /n", path);
  	//dir above curr path
  	sprintf(path, "%s%s", path, argv[1]);
  	printf("%s /n", path);
	  mkdir(argv[2], 0777);
  	link(argv[1], path);
  	unlink(argv[1]);
  }
}
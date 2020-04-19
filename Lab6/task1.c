// Grace Burton
// COSC350
// Lab 6 Task 1

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> // getenv() is found is stdlib
#include <string.h>

extern char** environ; // environment pointer

//name is the C string containing name of requested var
char* mygetenv(const char *name){

	char **directory = environ;
	char *retval;
	int length = strlen(name);
	int isFound;

	//Looks through the environment directory
	while(*(directory) != '\0'){

		isFound = 1;

	//& searches for the ith character of the "name" variable to see if name is actually an environment variable 
		for(int i = 0; i < length; i++){

			if((*directory)[i] != name[i]){

				isFound = 0; 
			}
		}

		//if the first char is found
		if(isFound == 1){

			//return directory variable found
			retval = *directory;
			break;
		}
		else{
			//else, move to next char and check there
			*directory++;
		}
	}

	if(isFound == 0){

		return NULL;
	}
	else{

		return retval;
	}

}

int main(int argc, char** argv){

	printf("The following is printed using mygetenv(): \n");
	printf("HOME path: %s\n", mygetenv("HOME"));
	printf("USER path: %s\n", mygetenv("USER"));
  	printf("PATH : %s\n\n", mygetenv("PATH"));
  	
}

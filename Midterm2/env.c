//environment variable examples
//slides 12 
	
	//getenv.c retrieves some envron variables
	
	//setenv.c sets a created env "TEST11"
		//With setenv(), If a environment name is exist,
		//If rewrite is non-zero, the existing definition will be removed.
		//If rewrite is zero, the existing definition will NOT be removed

	//putenv.c
		//With putenv() function we can put a new environment variable during the process running

// -------------------------------------------------

// /* getenv.c */

// #include <stdlib.h>
// #include <stdio.h>

// int main(){
	
// 	printf("HOME=%s\n",getenv("HOME"));
// 	printf("PATH=%s\n",getenv("PATH"));
// 	printf("ROOTPATH=%s\n",getenv("ROOTPATH"));

// 	return 0;
// }

// /* setenv.c */
// #include <stdlib.h>
// #include <stdio.h>
// int main(){

// 	char* env1 = getenv("TEST11");
// 	printf("TEST11=%s\n", env1);
// 	//show current env variable
// 	setenv("TEST11","abcd",1);
// 	//reset it
// 	env1 = getenv("TEST11");
// 	printf("TEST11=%s\n", env1);

// 	return 0;
// }

/*putevc.c*/

#include <stdlib.h>
#include <stdio.h>

int main(){

	putenv("MYENV=park");
	printf("MYENV=%s\n", getenv("MYENV"));

	return 0;
}
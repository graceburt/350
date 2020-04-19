//dynamic memory allocation examples
//slides 12 

	//malloc.c shows how to partition struct data 

	//calloc.c specifies how much data is used -only amount needed

	//calloc1.c does ^^ and collects data from command line

	//calloc2.c does ^^ and sends data to a list

// -------------------------------------------------

// /* malloc.c */
// #include <stdio.h>
// #include <stdlib.h> 
// #include <string.h>

// int main(){

// 	typedef struct{
// 		int age;
// 		char name[20];
// 		}  data;

// 	data *bob;
// 	bob = (data*) malloc( sizeof(data) );

// 	if( bob != NULL ) {
// 		bob->age = 22;
// 		strcpy( bob->name, "Robert");
// 		printf( "%s is %d years old\n", bob->name, bob->age );
// 	}
	
// 	free( bob );

// 	return 0;

// 	}

// /* calloc.c */
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>

// int main(){
// 	typedef struct data_type {
// 		int age;
// 		char name[20];
// 	}  data;

// 	data *bob;
// 	bob = (data*) calloc( 2,sizeof(data) );

// 	if( bob != NULL ) {

// 		bob[0].age = 22;
// 		strcpy( bob[0].name, "Robert");
		
// 		bob[1].age = 25;
// 		strcpy(bob[1].name, "Christine");

// 		printf( "%s is %d years old\n", bob[0].name, bob[0].age );
// 		printf( "%s is %d years old\n", bob[1].name, bob[1].age );}

// 		free( bob );
// 		return 0;
// }

// /* calloc1.c */
// #include <stdio.h>
// #include <stdlib.h>

// int main(){
// 	int i, n;
// 	int* a;

// 	printf("Number of elements to be entered:");
// 	scanf("%d",&n);

// 	a = (int*)calloc(n, sizeof(int));

// 	printf("Enter %d numbers:\n",n);

// 	for( i=0 ; i< n ; i++ ){

// 		scanf("%d",&a[i]);
// 	}

// 	printf("The numbers entered are: ");

// 	for( i=0 ; i< n ; i++ ){
// 		printf("%d ",a[i]);
// 	}

// 	free(a);
// 	return(0);
// }

/* calloc2.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int i, n;
	char name[20];
	int age;
	typedef struct{
		int age;
		char name[20];
	}  data;

	data* list;
	printf("Number of students to be entered in the list:");
	scanf("%d",&n);
	list = (data*) calloc( n,sizeof(data) );

	for(i=0; i< n; i++){
		printf("Enter name: \n");
		scanf("%s",name);
		strcpy(list[i].name, name);
		printf("Enter age: \n");
		scanf("%d", &age);
		list[i].age = age;
	}

	printf("YOUR STUDENT LIST\n");
	for(i=0; i< n; i++){
		printf("%s    %d \n",list[i].name, list[i].age);
	}

	free( list );
	return 0;
}
// Grace Burton
// COSC350
// Lab 8 Task 1

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_THREADS 2

//*****COMPILE WITH -PTHREAD IN -o STEP!!!*****

//Write a C program which accepts an integer argument 
// and calculates sum up and factorial(1 + 2 + 3 +...+ n, and 1 ×2 ×3 ×...×n). 
//Instead of calling sequence of two functions,two threads will be created and each thread works for different task concurrently. 

int myatoi(char *str){
	int num = 0;
	int index = 0;

	while(str[index] != '\0')
	{
		num = (num * 10) + (str[index] - 48);
		index++;
	}
	return num;
}

void *Sum(void *n){

	int ans = 0;
	int num = (intptr_t)(n);

	for(int i = 0; i <= num; i++){

		ans += i;
	}

	printf("The sum of %d = %d\n", num, ans);
}

// function calculates the factorial in the new thread.
int findFactorial(int fact){

  if (fact == 0){
      return 1; 
  }

    return fact * findFactorial(fact - 1); 
}

void *getFactorial(void *scores){

  int n = (intptr_t)scores;
  
  int ans = findFactorial(n);

  printf("The factorial of %d is %d.\n", n, ans);
  pthread_exit(NULL);

}

int main(int argc, char* argv[]){

	pthread_t sum, fact;

	if(argc != 2){

		printf("Not enough args!");
		exit(-1);
	}

	int num = myatoi(argv[1]);
	int rc1, rc2;

	//create thread for sum
	rc1 = pthread_create(&sum, NULL, Sum, (void*)(intptr_t)num);
	if(rc1){

		printf("ERROR; return code from pthread_create() is %d\n", rc1);
		exit(-1);
	}

	//create thread for fact
	rc2 = pthread_create(&fact, NULL, getFactorial, (void*)(intptr_t)num);
	if(rc2){
		
		printf("ERROR; return code from pthread_create() is %d\n", rc2);
		exit(-1);
	}

	void* add;
	void* prod;

	pthread_join(sum, &add);
	pthread_join(fact, &prod);

	pthread_exit(NULL);
	exit(0);

} 
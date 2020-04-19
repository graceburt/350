// Grace Burton
// COSC350
// Lab 8 Task 2

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

#define NUM_THREADS 4

//ERROR: SEG FAULT ????? in readScores @ start_thread?

//Three treads are sharing an integer array (you may define as global) and each thread do different jobs.
	//•Thread #1: get test scores from keyboard up to 20 and save into the array.
	//•Thread #2: Calculate an average score and Medium value and display.
	//•Thread #3: get the minimum and the maximum scoreand display.
	//•Thread #4: clear buffer and set to 0 and display after Thread #2, Thread #3 finishes its job. 

//Thread #2 and #3 must wait for thread #1 finish its job. Once thread #1 finish its job, thread #2 and thread #3 works concurrently. Thread #4 must wait for thread #2 and Thread #3 finish its job

int scores[20];

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

void *readScores(void* numScores){

	int score;
	int i;

	printf("Enter 20 scores, or -1 to quit.");

	while(i < 20){

			printf("Enter test score #%d\n", i);
			scanf("%d", &score);

			while(score < -1){

				printf("Invalid score input, grade cannot be negative.");
				printf("Enter test score #%d\n", i);
				scanf("%d", &score);
			}//end inside while

			scores[i] = score;

			if(score == -1){

				break;
			}

	}//end while

	// Sorting the array with selection sort. Will be helpful later with median, min, and max
		for(int k = 0; k < (i - 1); k++)
		{
			int min = k;
			for(int n = (k + 1); n < i; n++)
			{
				if(scores[n] < scores[min])
				{
					min = n;
				}
			}
			int temp = scores[k];
			scores[k] = scores[min];
			scores[min] = temp;
		}

	pthread_exit(NULL);

}

void *calcAvgScore(void* numScores){

	int i;
	int total = 0;
	float average, median;

	for(i = 0; scores[i] != -1; i++){

		total += scores[i];
	}

	if(i == 0){

		printf("Average and median are 0, since scores[] is empty.");
		pthread_exit(NULL);
	}

	//divide number of numbers in array by total
	average = ((float)total/i);

	//if even number of numbers split in half, then add those averages up
	if(i % 2 == 0)
	{
		int rhs = (i / 2) - 1;
		int lhs = i / 2;
		median = (float) (scores[rhs] + scores[lhs]) / 2;
	}
	else //else just regular average
	{
		median = scores[i / 2];
	}

	printf("The average score is %2.2f and the median score is %2.2f \n", average, median);

	pthread_exit(NULL);

}


void *calcMinMax(void* numScores)
{
	int i, max;
	// min can be assumed because the list was sorted in thread 1
	int min = scores[0];

	for(i = 0; scores[i] != -1; i++)
	{
		max = scores[i];
	}

	if(i == 0)
	{
		puts("The lowest and highest are 0 becuase there were no scores entered.");
		pthread_exit(NULL);
	}

	printf("The lowest score was a %d, and the highest was a %d \n", min, max);

	pthread_exit(NULL);
}

//emptying buffer
void *clearBuffer(void* numScores)
{
	int i;

	printf("Clearing buffer with all 0s\n");

	//literally just fill buffer with 0s
	for(i = 0; i < 20; i++)
	{
		scores[i] = 0;
		printf("%d ", scores[i]);
	}

	pthread_exit(NULL);
}


int main(int argc, char* argv[])
{
	//initialize the four threads used
	pthread_t THREAD[4];
	int rc, i;
	int n = 20;

	// Setting every position to -1 will be used to determine valid array positions later
	for(i = 0; i < 20; i++)
	{
		scores[i] = -1;
	}

	//Create thread 1, which recieves scores
	//Create thread 2 which calculates avg and median 
	//Combine the two so Thread 2 recieves information from Thread 1
	rc = pthread_create(&THREAD[0], NULL, readScores, (void *)(intptr_t)n);
	if(rc)
	{
		puts("Error ocurred when creating pthread for reading test scores.");
		exit(-1);
	}

	pthread_join(THREAD[0], NULL);

	rc = pthread_create(&THREAD[1], NULL, calcAvgScore, (void *)(intptr_t)n);
	if(rc)
	{
		puts("Error ocurred when creating pthread for reading test scores.");
		exit(-1);
	}

	//Create thread 3 whih finds min and max scores
	//Join thread 1&2 with thread 3 so thread 3 contains all the information from threads 1&2

	rc = pthread_create(&THREAD[2], NULL, calcMinMax, (void *)(intptr_t)n);
	if(rc)
	{
		puts("Error ocurred when creating pthread for reading test scores.");
		exit(-1);
	}

	pthread_join(THREAD[1], NULL);
	pthread_join(THREAD[2], NULL);

	//create thread 4, which clears the buf
	//combine threads 1&2&3 with 4 so 4 executes after the rest

	rc = pthread_create(&THREAD[3], NULL, clearBuffer, (void *)(intptr_t)n);
	if(rc)
	{
		puts("Error ocurred when creating pthread for reading test scores.");
		exit(-1);
	}

	pthread_join(THREAD[3], NULL);

	pthread_exit(NULL);

    return 0;
}
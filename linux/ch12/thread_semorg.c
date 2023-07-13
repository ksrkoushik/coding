#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void *thread_function(void *arg);
sem_t bin_sem;

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
int sval;
int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = sem_init(&bin_sem, 0, 0);
	sem_getvalue(&bin_sem, &sval);
	printf("Main: semaphore value is %d\n", sval);
	if(res!=0)
	{
		perror("Semaphore initialization failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if(res!=0)
	{
		perror("thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Input some text, Enter 'end' to finish\n");
	while(strncmp("end", work_area, 3)!= 0)
	{
		fgets(work_area, WORK_SIZE, stdin);
		sem_post(&bin_sem);//increments the sem value
		sem_getvalue(&bin_sem, &sval);
		printf("Main: semaphore value is %d\n", sval);
	}
	printf("\nWaiting for thread to finish..\n");
	res = pthread_join(a_thread, &thread_result);
	if(res!=0)
	{
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	sem_getvalue(&bin_sem, &sval);
	printf("Main: semaphore value is %d\n", sval);
	//here the main sem value will be 1
	printf("Thread joined\n");
	//the thread gets joined once the new thread terminates
	//and its exit status is stored in memory pointed by the thread_result
	//which will be retrieved by the main thread and hence in the the end
	//the semaphore value will be the same in both main and new threads.
	sem_destroy(&bin_sem);
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	sem_wait(&bin_sem);//decrements the sem value
	sem_getvalue(&bin_sem, &sval);
	printf("Thread: semaphore value is %d\n", sval);
	while(strncmp("end", work_area, 3)!=0)
	{
		printf("You input %ld characters\n", strlen(work_area)-1);
		sem_wait(&bin_sem);
		//here as already sem value is 0 with the first sem_wait,
		//now it will not do anything except waiting for a non-zero
		//count value of semaphore
		sem_getvalue(&bin_sem, &sval);
	        printf("Thread: semaphore value is %d\n", sval);
	}
	pthread_exit(NULL);
}



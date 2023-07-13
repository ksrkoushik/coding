#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

//In this, we will be extra careful that the access to critical variables
//is given onle to one thread at a time.

void *thread_function(void *arg);//declaring a pointer to thread func
pthread_mutex_t work_mutex;// declaring a mutex
//this protects both work area and time_to_exit
#define WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;

int main()
{
	int res;
	pthread_t a_thread;
	void *thread_result;
	//mutex initialization
	res = pthread_mutex_init(&work_mutex, NULL);
	if(res != 0)
	{
		perror("Mutex initialization failed");
		exit(EXIT_FAILURE);
	}
	// A new thread creation
	res = pthread_create(&a_thread, NULL, thread_function, NULL);
	if(res != 0)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	//first this new thread tries to lock the mutex,
	//if it's already locked, the call will block until it is released.
	pthread_mutex_lock(&work_mutex);
	printf("Input some text, Enter 'end' to finish\n");
	while(!time_to_exit)
	{
		fgets(work_area, WORK_SIZE, stdin);
		pthread_mutex_unlock(&work_mutex);
		while(1)
		{
			pthread_mutex_lock(&work_mutex);
			if(work_area[0] != '\0')
			{
				pthread_mutex_unlock(&work_mutex);
				sleep(1);
			}
			else
			{
				break;
			}
		}
	}
	pthread_mutex_unlock(&work_mutex);
	printf("\nWaiting for thread to finish...\n");
	res = pthread_join(a_thread, &thread_result);
	if(res != 0)
	{
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined\n");
	pthread_mutex_destroy(&work_mutex);
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	sleep(1);
	pthread_mutex_lock(&work_mutex);
	while(strncmp("end", work_area, 3) != 0)
	{
		printf("You input %ld characters\n", strlen(work_area) -1);
		work_area[0] = '\0';
		pthread_mutex_unlock(&work_mutex);
		sleep(1);
		pthread_mutex_lock(&work_mutex);
		while(work_area[0] == '\0')
		{
			pthread_mutex_unlock(&work_mutex);
			sleep(1);
			pthread_mutex_lock(&work_mutex);
		}
	}
	time_to_exit = 1;//setting the time_to_exit if we want to exit
	work_area[0] = '\0';
	pthread_mutex_unlock(&work_mutex);
	pthread_exit(0);
}
			

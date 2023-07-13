#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

void *thread_fun(void *arg);
sem_t bin_sem;// binary semaphore
// binary semaphores are used to protect a piece of code so that only one thread
// of execution can run it at any one time.
#define WORK_SIZE 1024//this a macro created
char work_area[WORK_SIZE];
int sval;
int main()
{
	int res;
	pthread_t a_thread;
	void *thread_res;
	res = sem_init(&bin_sem, 0, 0);// initializing the semaphore object
	//&bin_sem: the func is pointing to a semaphore object
	//second arg is "pshared", if it is 0, we say that semaphore is local
	// to the current process, otherwise the semaphore may be 
	// shared between processes.
	// In this chap, we dont pass a non-zero value for pshared, if passed 
	// it will cause the call to fail.
	sem_getvalue(&bin_sem, &sval);
	printf("Main: semaphore value is %d\n",sval);
	if (res != 0)
	{
		perror("Semaphore initialization failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_create(&a_thread, NULL, thread_fun, NULL);
	if (res != 0)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Input some text, Enter 'end' to finish...\n");
	while(strncmp("end", work_area, 3)!= 0)
	{
		fgets(work_area, WORK_SIZE, stdin);
		sem_post(&bin_sem);
	//sem_post atomically increases the value of semaphore by 1
		sem_getvalue(&bin_sem, &sval);
		printf("Main: semaphore value is %d\n", sval);
	}
	printf("\nWaiting for the thread to finish\n");
	res = pthread_join(a_thread, &thread_res);
	if (res != 0)
	{
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	sem_getvalue(&bin_sem, &sval);
	printf("Main: semaphore value is %d\n", sval);
	printf("Thread joined\n");
	sem_destroy(&bin_sem);
	exit(EXIT_SUCCESS);

}

void *thread_fun(void *arg)
{
	sem_wait(&bin_sem);//sem_wait atomically decreases the value
			  // of semaphore by one, but waits until the 
			  // semaphore has a non-zero count first.
	sem_getvalue(&bin_sem, &sval);
	printf("Thread: semaphore value is %d\n", sval);
	while(strncmp("end", work_area, 3))
	{
		printf("%ld\n", strlen(work_area));
		printf("You entered %ld characters\n", strlen(work_area)-1);
		sem_wait(&bin_sem);
		sem_getvalue(&bin_sem, &sval);
		printf("Thread: semaphore value is %d\n", sval);
	}
	pthread_exit(NULL);
}
		

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void *thread_fun(void *arg); 
// declaring a prototype for the function  that the thread 
// will call when you create it

sem_t bin_sem; //declaring a semaphore(binary)
#define WORK_SIZE 1024//define is a pre-processor directive
//define is used to create constant values which are often used 
//for defining worksizes or other parameters.
char work_area[WORK_SIZE];
//this enables to create a work area with a size of 1024 characters
int sval;
int main()//any C program starts from this function
{
	int res;//declaring an integer variable
	pthread_t a_thread;//declaring a thread variable
	void *thread_res;// 
	res = sem_init(&bin_sem,0,0);
	//initializing a semaphore object pointed to by sem,
	//2nd arg is "pshared", it controls the type of semaphore
	//and if it's value is 0, the sem is local to current process,
	//otherwise the sem may be shared b/w processes
	//3rd arg is initialized value of sem, here it initialized to 0
	sem_getvalue(&bin_sem, &sval);
	printf("Main: bin_sem value is %d\n", sval);
	//printf("Now the return value of res is %d\n", res);
	if(res != 0)
	{
		perror("semaphore initialization failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_create(&a_thread, NULL, thread_fun, NULL);
	// we pass the address of pthread_t object that we can use to refer
	// to the thread afterward.
	// 2nd arg is NULL means we dont wnat to modify
	// default thread attributes.
	// The 3rd and 4th parameters are the function to call and
	// a parameter to pass to it.
	//printf("Now the return value of res is %d\n", res);
	if(res != 0)
	{
		perror("thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Input some text, Enter 'end' to finish\n");
	while(strncmp("end", work_area, 3) != 0)
	{
		fgets(work_area, WORK_SIZE, stdin);
		sem_post(&bin_sem);
		sem_getvalue(&bin_sem, &sval);
		printf("Main: bin_sem value is %d\n", sval);
	}
	printf("\nWaiting for thread to finish..\n");
	
	res = pthread_join(a_thread, &thread_res);
	//printf("now the return value of res is %d\n", res);
	if(res != 0)
	{
		perror("thread join failed");
		exit(EXIT_FAILURE);
	}
	sem_getvalue(&bin_sem, &sval);
	printf("Main: bin_sem value is %d\n", sval);
	printf("Thread joined\n");
	sem_destroy(&bin_sem);
	exit(EXIT_SUCCESS);
}

void *thread_fun(void *arg)
{
	sem_wait(&bin_sem);
	sem_getvalue(&bin_sem, &sval);
	printf("Thread: bin_sem value is %d\n", sval);
	while(strncmp("end", work_area, 3)!=0)
	{
		printf("Your input has %ld characters\n", strlen(work_area)-1);
		printf("this thread is waiting for the 'end'\n");
		sem_wait(&bin_sem);
		sem_getvalue(&bin_sem, &sval);
		printf("Thread: bin_sem value is %d\n", sval);
		
	}
	printf("now the thread got its 'end'\n");
	pthread_exit(NULL);
}
	


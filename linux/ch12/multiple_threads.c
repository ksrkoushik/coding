#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 6 //this is a constant that can be used repeatedly in the code

void *thread_function(void *arg);//pointer to function

int main()
{
	int res;
	//creating an array of thread ids	
	pthread_t a_thread[NUM_THREADS];
	void *thread_result;//used to hold the value returned by new thread
	int lots_of_threads;//just an integer variable
	//Loop around creating several threads
	for(lots_of_threads=0; lots_of_threads< NUM_THREADS; lots_of_threads++)
	{
		res = pthread_create(&(a_thread[lots_of_threads]),NULL, thread_function, (void *)&lots_of_threads);
		if(res != 0)
		{		
			perror("Thread Creation failed");
			exit(EXIT_FAILURE);
		}	
		sleep(1);
		
	}
	printf("Waiting for threads to finish...\n");
	for(lots_of_threads = NUM_THREADS -1;lots_of_threads >=0;lots_of_threads--)
	{
		res = pthread_join(a_thread[lots_of_threads], &thread_result);
		if(res == 0)
		{
			printf("Picked up a thread\n");
		}
		else
		{
			perror("pthread_join failed");
		}
	}
	printf("All done\n");
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	int my_number = *(int *) arg;//this is a typecast exprn
	//that converts a geberic pointer arg to a pointer to an integer
	//and then deferences that pointer using the * operator to obtain 
	//the value of the integer being pointed to.
	int rand_num;
	printf("thread_function is running.Arg was %d\n", my_number);
	rand_num = 1 + (int)(9.0*rand()/(RAND_MAX + 1.0));//type casting to int
	sleep(rand_num);
	printf("Bye from %d\n", my_number);
	pthread_exit(NULL);
}

	

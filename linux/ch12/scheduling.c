#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *thread_function(void *arg);//declaring a pointer for threadfun
char message[] = "Hello world";
int thread_finished = 0;// a simple flag to allow the main thread to detect
// whether the child has finished and to show that the threads are still 
// sharing variables.

int main()
{
	int res;
	pthread_t a_thread;//declaring a thread object
	pthread_attr_t thread_attr;//declaring a thread attribute object

	//Additional variables for scheduling
	int max_priority;
	int min_priority;
	struct sched_param scheduling_value;

	//Initialization of Thread attribute
	res = pthread_attr_init(&thread_attr);
	if(res != 0)
	{
		perror("Attribute creation failed");
		exit(EXIT_FAILURE);
	}
	//Setting of Detach attribute
	res = pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
	if(res != 0)
	{
		perror("Setting detached attribute failed");
		exit(EXIT_FAILURE);
	}
	res = pthread_attr_setschedpolicy(&thread_attr, SCHED_OTHER);
	if(res != 0)
	{
		perror("Setting Scheduling Policy failed");
		exit(EXIT_FAILURE);
	}
	//Initializing additional variables for scheduling
	max_priority = sched_get_priority_max(SCHED_OTHER);
	min_priority = sched_get_priority_min(SCHED_OTHER);
	
	//Setting scheduling priority
	scheduling_value.sched_priority = min_priority;
	res = pthread_attr_setschedparam(&thread_attr, &scheduling_value);
	if(res != 0)
	{
		perror("Setting scheduling priority failed");
		exit(EXIT_FAILURE);
	}
	
	//Thread creation
	res = pthread_create(&a_thread, &thread_attr, thread_function, (void *) message);
	if(res != 0)
	{
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	//Destroying Thread once it is finished
	(void)pthread_attr_destroy(&thread_attr);
	while(!thread_finished)
	{
		printf("Waiting for thread to say it's finished..\n");
		sleep(1);
	}
	printf("Other thread finished, bye!\n");
	exit(EXIT_SUCCESS);
}

void *thread_function(void *arg)
{
	printf("thread_function is running..Argument was %s\n", (char *)arg);
	sleep(4);
	printf("Second thread setting finshed flag and exiting now\n");
	thread_finished = 1;
	pthread_exit(NULL);
}

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
void *thread_fun(void *arg);
char msg[] = "Welcome to the world of threads";

int main()
{
	int new;
	pthread_t first_thread;
	void *result;
	new = pthread_create(&first_thread, NULL, thread_fun, (void *) msg);
	if(new != 0)
	{
		perror("Thread creation failed\n");
		exit(EXIT_FAILURE);
	}
	printf("A new thrd func is created, please wait till it finishes\n");
	new = pthread_join(first_thread, &result);
	if(new != 0)
	{
		perror("Thread joining failed\n");
		exit(EXIT_FAILURE);
	}
	printf("You have now executed a new thread\n");
	printf("Please wait while the new thread joins with the main thread\n");
	sleep(5);
	printf("thrd is now joined with main,it returned %s\n",(char *)result);
	printf("You are now exiting the main thread... Good Bye\n");
	exit(EXIT_SUCCESS);
}

void *thread_fun(void *arg)
{
	printf("thread func is running and its argument is:%s\n", (char *) arg);
	sleep(5);
	strcpy(msg,"Thread processing done");
	pthread_exit("Thank you CPU for giving your valuable time");
}

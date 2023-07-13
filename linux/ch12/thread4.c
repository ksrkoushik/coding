#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_fun(void *arg);
// declaring a protoype function that will be called when thread is created

char msg[] = "Welcome to the world of threads";
int main()
{
	int new;
	pthread_t first_thread;
	void *result;
	new = pthread_create(&first_thread, NULL, thread_fun, (void *)msg);
	if (new != 0)
	{
		perror("Thread creation failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Please wait while thread finishes its task\n");
	new = pthread_join(first_thread, &result);
	if (new != 0)
	{
		perror("Thread join failed\n");
		exit(EXIT_FAILURE);
	}
	printf("You have now executed a new thread function\n");
	printf("Pls wait,while this new thread gets joined with main thread\n");
	sleep(5);
	printf("The thrd is joined with main,it returned %s\n",(char *)result);
	printf("You are now exiting the main thread...%s\n", msg);
	exit(EXIT_SUCCESS);
}
int sum()
{
	int a,b,c;
	printf("Enter the two integer numbers for addition\n");
	scanf("%d\n", &a);
	scanf("%d", &b);
	c = a + b;
	printf("Pls wait for 5 seconds!you will get the result in a moment\n");
	sleep(5);
	printf("The computed sum value is %d\n",c);
	return c;
}
int product()
{
	int a,b,c;
	printf("Enter the two integer numbers for multiplication\n");
	scanf("%d\n", &a);
	scanf("%d", &b);
	c = a * b;
	printf("Pls wait for 5 seconds!.you will get the result in a moment\n");
	sleep(5);
	printf("The computed product value is %d\n", c);
	return c;
}
void *thread_fun(void *arg)
{
	printf("Thread func is running and argument is: %s\n", (char *) arg);
	printf("Please wait the computation is going on..\n");
	sum();
	product();
	strcpy(msg, "Computation done!!!");
	pthread_exit("Thank you CPU for giving your valuable time");
}




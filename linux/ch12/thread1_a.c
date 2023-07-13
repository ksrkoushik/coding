#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg);
// creating a prototype for the the function that the thread will call when you create it,It takes a pointer to void as its only argument and returns a pointer to void.
int run_now = 1;
char msg[] = "Hello world";

int main()
{
	// declaring some variables
	int res;
	pthread_t a_thread;
	void *thread_result;

	res = pthread_create(&a_thread, NULL, thread_function, (void *) msg);
	// &a_thread: passing the address of a pthread_t object.
	// NULL: passing NULL means we dont want to modify the default
	// thread attributes.
	// The final two args are the function to call and
	// a parameter to pass to it
	int print_count1 = 0;
	// If the call succeeds, two threads will now be running.
	// The original thread(main) continues and executes the code after 
	// pthread_create, and a new thread starts executing 
	// in the imaginatively named thread_function.
	// The original thread checks that the new thread started and then calls 	// pthread_join
	while(print_count1++ < 20)
	{
		if(run_now == 1)
		{
			printf("Main thread is running with 1\n");
			run_now = 2;
		}
		else
		{
			sleep(1);
		}
	}
	if(res != 0)
	{
		perror("Thread creation failed\n");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread to finish\n");
	res = pthread_join(a_thread, &thread_result);
	if(res != 0)
	{
		perror("Thread join failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Thread joined, it returned %s\n", (char *) thread_result);
	printf("Message is now %s\n", msg);
	exit(EXIT_SUCCESS);

}

void *thread_function(void *arg)
{
	int print_count2 = 0;
	while(print_count2++ < 20)
	{
		if(run_now == 2)
		{
			printf("Now new thread is running with 2\n");
			run_now = 1;
		}
		else
		{
			sleep(1);
		}
	}
	
	printf("Thread function is running with arg: %s\n", (char *) arg);
	sleep(3);
	strcpy(msg, "Good Bye!");
	pthread_exit("Thank you CPU for your valuable time");
	
}



	


//This program creates a single thread, shows that it is sharing variables with the original thread, and gets the new thread to return a result to the original thread.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

void *thread_function(void *arg); // defining a function

char message[] = "Hello world";// text msg created to pass on to pthread_create

int main()//any c program starts with this function
{
	int res;// integer variable create to hold the object pthread_create
	pthread_t a_thread;// creation of an object variable
	void *thread_result;// pointer variable created

	res = pthread_create(&a_thread, NULL, thread_function, (void *) message);
	// &a_thread --> points to mem location and enables 
	// you to refer to thread.
	// NULL --> here we are not passing any thread arguments.
	// thread_function---> what thread has to execute.
	// message --> a string argument to passed to the function.

	if(res != 0)
	//if thread returns non-zero value, execute the below code block
	{
		perror("Thread creation failed\n");
		exit(EXIT_FAILURE);
	}
	// if thread is successfully created, then the below lines are executed
	printf("Waiting for thread to finish\n");
	// now we join the thread function with the main thread
	res = pthread_join(a_thread, &thread_result);
	// a_thread --> this parameter waits for the identifier created
	//  in pthread_create &thread_result is a pointer to a pointer that
	//  itself points to the return value from the thread
	if(res != 0)
	{
		perror("Thread join failed\n");
		exit(EXIT_FAILURE);
	}

	printf("Thread joined, it returned %s\n", (char *) thread_result);
	printf("Message is now %s\n", message);
	exit(EXIT_SUCCESS);

}

void *thread_function(void *arg)
{
	printf("Thread function is running. Argument was %s\n",(char *) arg);
	sleep(3);
	strcpy(message, "Good Bye!");
	//here we updating the message, earlier it was "Hello world"
	pthread_exit("Thank you for the CPU time");
	// this return string is captured by thread_result
}

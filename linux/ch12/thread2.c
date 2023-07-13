//This program creates a single thread, shows that it is sharing variables with the original thread, and gets the new thread to return a result to the original thread.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <signal.h>
void *thread_function(void *arg); // defining a function

char message[] = "Hello world";

void bang(int sig)// defining a function bang to catch the interrupt signal
{
	printf("Bang!!!!!I got a signal whose number is %d\n", sig);
	(void) signal(SIGINT, SIGCONT);
	//After catching the signal, we define the action by passing SIGCONT
	//to enable to continue
}
int main()//any c program starts with this function
{
	int res;//declaring integer variable res
	pthread_t a_thread;//// declaring a thread variable a_thread
	void *thread_result;//declaring a pointer variable thread_result
	struct sigaction act1;//declaring a structure called sigaction
			      //naming it as act1
	act1.sa_handler = bang;//this the signal handler which the action
			       //to be taken
	sigemptyset(&act1.sa_mask);//we are keeping empty mask
	act1.sa_flags = 0;//no flags used
	sigaction(SIGINT, &act1,0);//sigaction catching the sigint signal

	res = pthread_create(&a_thread, NULL, thread_function, (void *)message);

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
	printf("Message is now %s\n", message);
	exit(EXIT_SUCCESS);

}

void *thread_function(void *arg)
{
	printf("Thread function is running. Argument was %s\n",(char *) arg);
	sleep(3);
	strcpy(message, "Good Bye!");
	pthread_exit("Thank you for the CPU time");
}

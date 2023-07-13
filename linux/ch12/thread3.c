#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
void *thd_fun(void *arg);// declaring a prototype function that will be called
			 // when thread is created
char message[] = " It's all about threads";// printing a line of text

int main()
{
	int new_thd;// creation of an integer variable called new_thd
	pthread_t thread_1;// creation of a thread object thread_1
	void *thd_result;// creation of a pointer variable thd_result
	new_thd = pthread_create(&thread_1, NULL, thd_fun, (void *) message);
	// this is creation of new thread
        if(new_thd != 0)
	{
		perror("Thread creation failed\n");// if thread failed
 		exit(EXIT_FAILURE);
	}
        printf("Waiting for thread to finish\n");// thread execution started
        new_thd = pthread_join(thread_1, &thd_result);//
        if(new_thd != 0)
	{	
	       perror("Thread join failed\n");
	       exit(EXIT_FAILURE);
	}
        printf("Thread joined, it returned %s\n", (char *) thd_result);
        printf("This is now %s\n", message);
        exit(EXIT_SUCCESS);
}
void *thd_fun(void *arg)
{
	printf("Thread function is running.Argument is: %s\n", (char *) arg);
	sleep(3);
	strcpy(message, "Bye!");
	pthread_exit("Thank you CPU for your valuable time");
}
              

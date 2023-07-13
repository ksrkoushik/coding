#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

//signal handler function
int i = 0;
void sigintHandler(int signum)
{
	i++;
	if(i>=2)
	{
		printf("Received second SIGINT signal...Terminating it...\n");
		exit(0);
	}
	else
	{
		printf("Received SIGINT signal....Ignoring it...\n");
	}
}


int main()
{
	//Register the signal handler for SIGINT
	signal(SIGINT, sigintHandler);
	printf("Running..Press Ctrl + C to send SIGINT signal.\n");
	while(1)
	{
	}
	return 0;
}

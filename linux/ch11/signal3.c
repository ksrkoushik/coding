#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int i = 0;//counter to keep track of CTRL + C

//signal handler function for SIGINT
void signalHandler(int signum)
{
	i++;//increment the counter
	if(i == 1)
	{
		printf("Received SIGINT signal for the first time...ignored it..\n");
	}
	else if (i == 2)
	{
		printf("Received SIGINT signal for the second time, redirecting it to SIGTERM..\n");
	raise(SIGTERM);
	printf("Received SIGTERM signal...so Terminating now..\n");
	exit(0);
	}
}

int main()
{
	//Register the signal handler for SIGINT
	signal(SIGINT, signalHandler);
	printf("Running...Press CTRL + C to send SIGINT signal..\n");
	while(1)
	{
	}
	return 0;
}
	
	


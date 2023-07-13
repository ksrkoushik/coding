#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void sigtermHandler(int signum)
{
	printf("received SIGTERM signal...hence terminating..\n");
	exit(0);
}
void sigintHandler(int signum)
{
	printf("Received sigint signal....ignoring it\n");
	signal(SIGINT,sigtermHandler);
}
int main()
{
	signal(SIGINT, sigintHandler);
	printf("Running Ctrl + C to send SIGINT signal.\n");
	while(1)
	{
	}
	return 0;
}

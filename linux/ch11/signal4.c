#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigtermHandler(int sig)
{
	raise(SIGTERM);
	
}
int main()
{
	pid_t pid;
	printf("Alarm Application Starting...\n");
	pid = fork();
	if(pid == -1)
	{
		perror("fork failed..\n");
		return 1;
	}
	else if(pid == 0)
	{
		//this is child process
		printf("We are in Child...PID : %d \n", getpid());
		raise(SIGALRM);
		return 0;
	}
	//here we are in Parent Process
	printf("Waiting for the Alarm to go off...PID : %d \n", getpid());
	printf("Alarm will be terminated...Its all over now..\n");
	sleep(3);
	(void) signal(SIGALRM, sigtermHandler);
	return 0;
}
	

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
int count = 0;
void sigintHandler(int signum)
{
	signal(SIGINT, SIG_DFL);
	printf("Child process %d exited..\n", getpid());
}

int main()
{
	pid_t childPid;
	int i;
	//Register signal handler for SIGINT
	signal(SIGINT, sigintHandler);
	
	printf("Parent: Parent process started with PID %d\n", getpid());
	
	//Fork multiple child processes
	for(i = 0; i < 3; i++)
	{
		childPid = fork();
		if(childPid < 0){
			perror("Fork failed\n");
			exit(1);
		}else if(childPid == 0){
			//child process
			// Register signal handler for SIGINT
			signal(SIGINT, sigintHandler);
			printf("Child: Child process %d started\n", getpid());
		}
	}
	//Parent process sleeps for a few seconds
	sleep(10);
	printf("Parent process exiting\n");
	return 0;
}
		

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
	if (pid == -1)
	{
		fprintf(stderr, "fork failed\n");
		return 1;
	}
	else if(pid == 0)
	{
		//child process
		printf("Child process started (PID: %d)\n", getpid());
		printf("Child process is exiting\n");
		exit(0);//child process exits
	}
	else
	{
		//parent process
		printf("Parent process started (PID: %d)\n", getpid());
		sleep(10);
		printf("Parent process exiting\n");
	}
	return 0;
}
		

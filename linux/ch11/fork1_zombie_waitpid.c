#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();
	if(pid == -1)
	{
		fprintf(stderr, "fork failed\n");
		return 1;
	}
	else if(pid == 0)
	{
		//child process
		printf("Child process started (PID: %d)\n", getpid());
		printf("Child process exiting..\n");
		exit(0);//child process exits
	}
	else
	{
		//parent process
		printf("Parent process started (PID: %d)\n", getpid());
		int status;
		waitpid(pid, &status, 0);//wait for the child to finish
		printf("Parent process exiting..\n");
	}
	return 0;
}
//The waitpid() function allows us to retrieve the exit status of the
//child process if needed		

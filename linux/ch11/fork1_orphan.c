#include <stdio.h>
#include <unistd.h>

int main()
{
	pid_t pid = fork();//create a new child process
	if(pid == -1)
	{
		fprintf(stderr, "fork failed\n");
		return 1;
	}
	else if(pid == 0)
	{
		//child process
		printf("Hello from the child process! (PID: %d)\n", getpid());
		sleep(2);
		printf("child Process completed!\n");
	}
	else
	{
		//parent process
		printf("Hello from the parent process! (PID: %d)\n", getpid());
		printf("Child Process created with PID: %d\n", pid);
		printf("Parent process completed!\n");
	}
	return 0;
}
	

#include <unistd.h>
#include <stdio.h>

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
		printf("Hello from the child process!(PID: %d)\n", getpid());
	}
	else
	{
		//Parent process
		printf("Hello from parent process!(PID: %d)\n", getpid());
		printf("Child process created with PID: %d\n", pid);
	}
	return 0;
}

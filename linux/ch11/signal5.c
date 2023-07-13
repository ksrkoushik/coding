#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void sigHandler(int signum)
{
	printf("Signal %d received by child process %d\n", signum, getpid());
	signal(SIGINT, SIG_DFL);
}

int main()
{
	pid_t child_pid;
	int status;
	
	//create a child process
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("fork failed..\n");
		exit(1);
	}
	else if(child_pid == 0)
	{
		struct sigaction sa;
		sa.sa_handler = sigHandler;
		sigemptyset(&sa.sa_mask);
		sa.sa_flags = 0;
		sigaction(SIGINT, &sa, NULL);

		printf("Child process %d waiting for the signal..\n", getpid());
		while(1)
		{
			sleep(1);
		}
	}
	else
	{
		printf("Parent process: Forked child with PID %d\n", child_pid);
		wait(&status);
		if (WIFEXITED(status))
		{
			printf("Child process %d exited with status: %d\n", child_pid, WEXITSTATUS(status));
		}
		else if (WIFSIGNALED(status))
		{
			 printf("Child process %d terminated by signal: %d\n", child_pid, WTERMSIG(status));
		}
	}
	return 0; 
} 

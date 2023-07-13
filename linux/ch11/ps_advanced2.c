#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <semaphore.h>

//sem_t semaphore;
volatile sig_atomic_t signal_received = 0;
pid_t child_processes[3];
int num_children = 0;

void sigintHandler(int signum)
{
	if(signal_received == 0)
	{
		printf("\nParent: Received SIGINT signal..ignoring for the firsttime\n");
	signal_received = 1;
	}
	else
	{
		printf("\nParent: Again Received SIGINT signal..Now Terminating\n");
		for(int i = 0; i < num_children; i++)
		{
			kill(child_processes[i], SIGTERM);
			printf("Parent: Sent SIGTERM to child process %d\n", child_processes[i]);
			sleep(1);
		}
		exit(0);
	}
}

void sigchldHandler(int signum)
{
	int status;
	pid_t pid;
	
	while((pid = waitpid(-1, &status, WNOHANG))>0)
	{
		if(WIFEXITED(status))
		{
			printf("Parent: Child process %d exited with status: %d\n", pid, WEXITSTATUS(status));
		}
		else if(WIFSIGNALED(status))
		{
			printf("Parent: Child process %d terminated by signal: %d\n", pid, WTERMSIG(status));
		}
	}
}

int main()
{
	struct sigaction sa_int, sa_chld;
	pid_t childPid;
	int i;
	
	//setup signal handler for SIGINT
	sa_int.sa_handler = sigintHandler;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sigaction(SIGINT, &sa_int, NULL);

	//setup signal handler for SIGCHLD
	sa_chld.sa_handler = sigchldHandler;
	sigemptyset(&sa_chld.sa_mask);
	sa_chld.sa_flags = 0;
	sigaction(SIGCHLD, &sa_chld, NULL);

	printf("Parent: Parent process started with PID %d\n", getpid());
	
	// Initialize Semaphore
	//sem_init(&semaphore, 0, 0);

	//Fork multiple child processes
	for(i = 0; i < 3; i++)
	{
		childPid = fork();
		if(childPid < 0)
		{
			perror("Fork failed..\n");
			exit(1);
		}
		else if(childPid == 0)
		{
			//Child process
			//Setup signal handler for SIGINT
      			//sigaction(SIGINT, &sa_int, NULL);
			printf("Child: Child Process %d started\n", getpid());
			while(1)
			{
				//Wait for a signal to proceed
				//sem_wait(&semaphore);
				if(signal_received)
				{
				printf("Child: Child process %d resumed\n", getpid());
				//signal_received = 0;
				sleep(1);
				}
			}
				
			
			//Child process sleeps for a few seconds
			//sleep(5);
			//printf("Child: Child process %d exiting\n", getpid());
			exit(0);
		}
		else
		{
			//Parent process
			printf("Parent: Forked Child process with PID %d\n", childPid);
			child_processes[num_children++] = childPid;
		}
	}
	//Parent process sleeps until interrupted by a signal
	while(1)
	{
		sleep(1);
	}
	//Cleaning up Semaphore
	//sem_destroy(&semaphore);
	printf("Parent: Parent process exiting\n");
	return 0;
}

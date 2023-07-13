#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
static int alarm_fired = 0;
void ding(int sig)
{
	alarm_fired = 1;
}
int main()
{
	pid_t pid;
	printf("alarm application starting\n");
	pid = fork();
	switch(pid)
	{
		case -1:// failure case
			perror("fork failed");
			return 1;
		case 0:
			// child 
			sleep(5);
			kill(getppid(), SIGALRM);
			return 0;
	}
	//if we get here we are the parent process
	printf("waiting for the alarm to go off\n");
	(void) signal(SIGALRM, ding);
	pause();
	if (alarm_fired)
		printf("Ding!\n");
	printf("Done\n");
	return 0;
}
// when you run this program, it pauses for five seconds while it waits for the
// simulated alarm clock
// This alarm program starts a new process via fork. This child process sleeps for 
// five seconds and then sends a SIGALRM to its parent.
// The parent arranges to catch SIGALRM and then pauses until a signal is received.
// We do not call printf in the signal handler directly, 
// rather we set a flag and then
// check the flag afterward

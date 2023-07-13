#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
static int alarm_fired = 0;
void ding_dong(int sig)
{
	alarm_fired = 1;
}
void  boom(int sig)// defining a function "boom" to handle any interrupt signal
{
	 printf("BOOM! - I got an interrupt signal %d\n", sig);
	 // printing a line of text with interrupt signal no.
         (void) signal(SIGINT, SIG_DFL);
	 // this is when press CTRL + C 2nd time, it will get into SIG_DFL mode.
}
int main()
{
	(void) signal(SIGINT, boom);
	pid_t pid;
	printf("Alarm application is starting\n");
	pid = fork();
	switch(pid)
	{
		case -1:
			perror("fork failed\n");
			return 1;
		case 0:
			//child
			printf("Hey beware of the malicious websites\n\
don't click on any of the links....\n");
			sleep(5);
			printf("Hope you have understood the seriousness...\n");
			sleep(5);
			kill(getppid(), SIGALRM);
			return 0;
	}
	// if we get here, we are the parent process
	printf("Waiting for the alarm to go off\n");
	(void) signal(SIGALRM, ding_dong);
	pause();
	if (alarm_fired)
		printf("Ding-Dong!!!!...Ding-Dong!!!\n");
	printf("Done\n");
	return 0;
}


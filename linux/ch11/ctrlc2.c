#include <signal.h>
#include <stdio.h>
#include <unistd.h>
void ouch(int sig)
{
	printf("OUCH- I got a signal with signal number %d\n", sig);
}

int main()
{
	struct sigaction act;
	act.sa_handler = ouch;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, 0);

	while(1)
	{
		printf("Hello world\n");
		sleep(1);
	}
}

// When you run this version of the program, you always get a message when you type Ctrl+C because  SIGINT is handled repeatedly by sigaction. To terminate the program,
//  you have to type Ctrl+\, which  generates the SIGQUIT signal by default
//
// The program calls sigaction instead of signal to set the signal handler for Ctrl+C
//(SIGINT) to the function ouch. It first has to set up a sigaction structure that contains
// the handler, a signal mask, and flags. In this case, you don’t need any flags,
// and an empty signal mask is created with the new function, sigemptyset.

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void ouch(int sig)
{
	printf("OUCH- I got a signal !! with signal number %d\n", sig);
	(void) signal(SIGINT, SIG_DFL);
}
// the main function has to intercept the SIGINT signal generated when we type CTRL+C
// for the rest of the time, it just sits in an infinite loop, 
// printing a message once a second
int main()
{
	(void) signal(SIGINT, ouch);// when interrupt signal is received, 
				    // ouch function is called
	while(1)
	{
		printf("hello world\n");
		sleep(1);
	}
}

// Typing CTRL+C for the first time causes the program to react and continue,
// But when we type CTRL+C again, the program ends because the behavior 
// of the SIGINT has returned to the default behavior of causing the program to exit


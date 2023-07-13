#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void mem(int sig)//mem function
{
	printf("OH MY GOD !..It's a memory error and signal num is %d\n", sig);
	(int) signal(SIGSEGV, SIG_DFL);//here we are catching SI
}
void bang(int sig)//bang function
{
	printf("bang--I got a signal from a signal whose number is %d\n", sig);
	(int) signal(SIGINT, SIGCONT);// when we press CTRL+C for 2nd time 
				      
}
int main()// any c program starts from this function
{
	struct sigaction act_new, act2;
	act_new.sa_handler = bang;
	sigemptyset(&act_new.sa_mask);
	act_new.sa_flags = 0;
	sigaction(SIGINT, &act_new, 0);// here we are catching the 
					// CTRL+C interrupt and
				       // doing an action by passing "bang" function
	act2.sa_handler = mem;
	sigemptyset(&act2.sa_mask);
	act2.sa_flags = 0;
	sigaction(SIGSEGV, &act2, 0);

	while(1)
	{
		printf("Hello world\n");
		sleep(5);
		int num = 10;
		int *ptr = NULL;
		*ptr = num;
		printf("The value of num is %d\n", num);
	}
}

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void mem(int sig)
{
	printf("It's a Memory error... please be careful..%d\n", sig);
	(void)signal(SIGSEGV, SIG_DFL);
}

int main()
{
	struct sigaction act;
	act.sa_handler = mem;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGSEGV, &act, 0);

	while(1)
	{
		int num = 10;
		int *ptr = NULL;
		*ptr = num;
		printf("The value of num is %d\n", num);
	}
	return 0;
}



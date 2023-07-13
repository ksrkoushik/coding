#include <stdlib.h>
#include <stdio.h>

int main()//any c program starts with this function
{
	printf("Running ps with system\n");//printing a line of string
	system("ps ax &");//system call to execute the process in backgnd
	printf("Done\n");//this will not be printed in this case
	exit(0);
}

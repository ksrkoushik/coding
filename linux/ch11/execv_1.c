#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main()//any c program starts with this function
{
	char *const ps_argv[]= {"top", 0};// passing arguments
	printf("Running top using execv\n");// printing a line of text
	execv("/usr/bin/top", ps_argv);// executing "top" command from execv
	printf("Done\n");// printing a string
	return 0;// returns a value 0 on successful execution of program.
}

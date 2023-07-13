#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main()// any c program starts from this function
{
	char *const ps_argv[] = {"man","grep", 0};// passing arguments of man grep
	char *const ps_envp[] = {"PATH= /bin:/usr/bin", 0};// passing PATH variables
	printf("Running man with execve \n");// printing a line of text
	execve("/usr/bin/man", ps_argv, ps_envp);// executing "man grep" command from execve
	return 0;// returning a value 0 on succesful execution of the program.
}


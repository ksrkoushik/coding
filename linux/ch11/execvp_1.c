#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main()// any c program starts from this function
{
	char *const ps_argv[] = {"ls", 0};// passing arguments
	printf("Running ls with execvp\n");//printing a line of text
	execvp("ls",ps_argv);// executing ls command from execvp
	printf("Done\n");//printing a string
	return 0;// returns a value 0 on successful execution of program
}


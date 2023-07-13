#include <stdio.h>
#include <stdlib.h>
int main()// any c program starts with this function
{
	printf("Running pstree using system\n");// printing a line of text
	system("pstree");// running pstree command inside the system call
	printf("Done\n");// printing a string
	return 0;// returns a value 0 on successful execution of the program
}
// system command:
// int system(const char *string);
// The system function runs the command passed to it as a string and waits for it to
// complete.
// The drawback of system is that unless and until it is finished, we can't run any other task

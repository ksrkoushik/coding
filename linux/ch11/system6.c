#include <stdio.h>
#include <stdlib.h>
int main()// any c program starts with this function
{
	printf("Running ps ax in the background\n");// printing a line of text
	system("ps ax &");// executing command "ps ax &" inside system call
	printf("Done\n");// printing a string
	return 0;// returning a value 0 on successful execution of the program
}
// system command:
// int system(const char *string);
// The system function runs the command passed to it as a string and waits for it to 
// complete.
// The drawback of system call is that unless and until it is finished, we cannot 
// work with any other task.
// The command "ps ax &" makes to run the process in background

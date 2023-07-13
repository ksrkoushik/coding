#include <stdio.h>
#include <stdlib.h>
int main()// any c program starts from main function
{
	printf("Running ps with system\n");// printing a line of text
	system("ps ax");// calling a function called "system" which
			// takes a string argument
	printf("Done\n");//after the execution of system call this line
			// gets printed.
	return 0;//this is the return value on the successful
		// execution of the program
}

// system command:
// int system(const char *string);
// The system function runs the command passed to it as a string and waits for it to
//  complete.
//  The drawback of "system" call is that unless and until it finishes its execution
//  we can't run any other execution.

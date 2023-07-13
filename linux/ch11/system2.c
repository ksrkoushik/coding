#include <stdlib.h>
#include <stdio.h>
int main()// any c program starts with this fucntion
{
	printf("Running ifconfig command\n");// printing a line of text
	system("ifconfig");// calling a function called "system" by passing an argument
			   // as a command "ifconfig" to be searched
	printf("Done\n");// printing a string
	return 0;//returns a value 0 on successful execution of the program
}
// System command:
// int system( const char *string);
// The system function runs the command passed to it as a string and waits for it to 
// complete.
// The drawback of "system" function is that unless it is completed, 
// we cannot run any other process.

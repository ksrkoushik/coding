#include <stdlib.h>
#include <stdio.h>
int main()// any c program starts with this function
{
	printf("Displays the search string with grep in ifconfig\n");// prints a line of text
	system("ifconfig | grep ether");//here we are combining two commands ifconfig with grep
					//inside "system" function call
	printf("Done\n");// printing a string
	return 0;// returns a value 0 on successful execution of program
}
// system command:
// int system ( const char *string);
// The system function runs the command passed to it as a string and waits for it to 
// complete.
// The drawback with "system" call is that we can't run any other process unless it is done.

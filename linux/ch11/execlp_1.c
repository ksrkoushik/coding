#include <unistd.h>// this is the header file required for exec
#include <stdlib.h>// this is the header file required for system
#include <stdio.h> // this is a common header for I/O in C
int main()//any c program starts with this function
{
	printf("Running ifconfig with execlp\n");// printing a line of text
	execlp( "ifconfig", 0);// executing ifconfig with execlp
	printf("Done\n");// printing a string
	return 0;// returns a value 0 on successful execution of the program.
}
// here we are going to run a process from inside the process exec
// This "exec" function is much more efficient than "system" because
// the original program will no longer be running after the new one is started


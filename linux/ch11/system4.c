#include <stdio.h>
#include <stdlib.h>
int main()// any c program starts with this line
{
	printf("opens a text file using system and cat\n");//printing a line of text
	system(" cat /home/ec2-user/environment/file1.txt");// using cat command inside the system function
	printf("\nDone\n");//printing a string
	return 0;// returning a value 0 on successful execution of the program
}
// system command:
// int system( const char *string);
// The system function runs the command passed to it as a string and waits for it to 
// complete.
// The drawback of system function is that unless and until it is finished,
// we can't run any other task

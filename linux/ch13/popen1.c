#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()// any c program starts from this function
{
	FILE *read_fp;
	//declaring a pointer variable read_fp of FILE type
	char buffer[BUFSIZ + 1];
	//declaring a buffer with size BUFSIZ + 1
	int chars_read;
	//declaring an int variable chars_read
	memset(buffer, '\0', sizeof(buffer));
	//memset is used to create a block of memory
	//by initializing BUFSIZ(which is 8192 bytes with null bytes)
	printf("Buffer size is %d bytes\n", BUFSIZ);
	//printing the buffer size which 8192 bytes
	read_fp = popen("uname -a", "r");
	//popen is a stdlib fn that is used to create a pipe b/w
	//process and command shell and to execute a shell cmd with
	//I/O streams connected to the pipe.
	if(read_fp != NULL)//checking the return value of popen
	{
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		if(chars_read > 0)
		{
			printf("Output was :-\n%s\n", buffer);
		}
		pclose(read_fp);
		// pclose fn closes the pipe and waits for the child process
		// to terminate.If the child process has already terminated,
		// pclose returns immediately with the exit status of the 
		// child process.Otherwise, pclose waits for the child process
		// to terminate and then returns the exit status.
		printf("Number of bytes read %d\n", chars_read);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

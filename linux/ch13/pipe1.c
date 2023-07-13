#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// note that in this program, the file_pipes array, the address of which is passed
// to the pipe function as a parameter.
// The program creates a pipe using the two file descriptors in the array file_pipes[].// It then writes data into the pipe using the file descriptor file_pipes[1] and reads
// it back from file_pipes[0].
// Notice that the pipe has some internal buffering that stores the data b/w the calls //to write and read.
// The real advantage of pipes comes when you want to pass data b/w two processes.
int main()// any c program starts from this fn.
{
	int data_processed;//declaring an integer varaible
	int file_pipes[2];//declaring an integer array
	const char some_data[] = "12345";//declaring a string array
	char buffer[BUFSIZ + 1];//declaring the size using BUFSIZ
	//memset is a function that allows you to set a block of memory
	//to a specified value.
	memset(buffer, '\0', sizeof(buffer));//allocating memory 
	if(pipe(file_pipes) == 0)
	{
		data_processed = write(file_pipes[1], some_data, strlen(some_data));
		printf("Wrote %d bytes\n", data_processed);
		data_processed = read(file_pipes[0], buffer, BUFSIZ);
		printf("Read %d bytes: %s\n", data_processed, buffer);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

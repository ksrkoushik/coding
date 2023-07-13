#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	int data_processed;//declaring an int type variable "data_processed"
	int file_pipes[2];//declaring an int type array "file_pipes[2]"
	const char some_data[] = "123";//declaring a char type array "some_data[]"
	char buffer[BUFSIZ + 1];//declaring a char type variable "buffer"
	pid_t fork_result;//declaring a signed int data type represents a process id
	
	memset(buffer, '\0', sizeof(buffer));//memory allocation
	
	if(pipe(file_pipes) == 0)
	{
		fork_result = fork();//system call
		//calling the fork
		if(fork_result == -1)// when fork call fails
		{
			fprintf(stderr, "Fork failure");
			exit(EXIT_FAILURE);
		}
		if(fork_result == 0)//fork call success and we are in the child process
		{
			data_processed = read(file_pipes[0], buffer, BUFSIZ);
			printf("Read %d bytes: %s\n", data_processed, buffer);
			exit(EXIT_SUCCESS);
		}
		else// here we will be in parent process
		{
			data_processed = write(file_pipes[1], some_data, strlen(some_data));
			printf("Wrote %d bytes\n", data_processed);
		}
	}
	exit(EXIT_SUCCESS);
}

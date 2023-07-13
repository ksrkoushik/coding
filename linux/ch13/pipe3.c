#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
	int data_processed;//declaring an int variable "data_processed"
	int file_pipes[2];//declaring an int array "file_pipes[2]"
	const char some_data[] = "123";//declaring a char type arra "some_data[]"
	char buffer[BUFSIZ + 1];//declaring a char type variable "buffer"
	pid_t fork_result;//declaring a signed int data type variable "pid_t"

	memset(buffer, '\0', sizeof(buffer));//memory allocation
	
	if(pipe(file_pipes)==0)
	{
		fork_result = fork();//system call to fork process
		if(fork_result==(pid_t)-1)
		{
			fprintf(stderr, "Fork failure");
			exit(EXIT_FAILURE);
		}
		if(fork_result==0)
		{
			sprintf(buffer, "%d", file_pipes[0]);
			//storing file descriptor and data
			(void)execl("pipe4", "pipe4", buffer, (char *)0);
			//system call to execl for "pipe4" program
			exit(EXIT_FAILURE);
		}
		else
		{
			data_processed = write(file_pipes[1], some_data, strlen(some_data));
			printf("%d - wrote %d bytes\n", getpid(), data_processed);
		}
	}
	exit(EXIT_SUCCESS);
}

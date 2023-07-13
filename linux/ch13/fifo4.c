#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define FIFO_NAME "./tmp/my_fifo"
#define BUFFER_SIZE PIPE_BUF

int main()
{
	int pipe_fd;//declaring the int variable "pipe_fd"
	int res;//declaring an int variable "res"
	int open_mode = O_RDONLY;//declaring an int variable "open_mode"
	char buffer[BUFFER_SIZE + 1];//declaring a char buffer
	int bytes_read = 0;//declaring an int variable "bytes_read"
	
	memset(buffer, '\0', sizeof(buffer));//allocating memory
	printf("Process %d opening FIFO O_RDONLY\n", getpid());
	//fifo opening in read only blocking mode
	pipe_fd = open(FIFO_NAME, open_mode);
	printf("Process %d result %d\n", getpid(), pipe_fd);//get the process id
	
	if(pipe_fd != -1)
	{
		do//read from fifo file
		{
			res = read(pipe_fd, buffer, BUFFER_SIZE);
			bytes_read += res;//inc the bytes_read for next byte
		}
		while(res>0);//read when this condition is met
		(void)close(pipe_fd);//close the fifo file
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	printf("Process %d finished, %d bytes read\n", getpid(), bytes_read);
	exit(EXIT_SUCCESS);
}

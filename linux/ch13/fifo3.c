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
#define TEN_MEG (1024 * 1024 * 10)

int main()
{
	int pipe_fd;//declaring an int varaible "pipe_fd"
	int res;//declaring an int variable "res"
	int open_mode = O_WRONLY;//declaring an in variable "open_mode"
	int bytes_sent = 0;//declaring an int variable "bytes_sent"
	char buffer[BUFFER_SIZE + 1];//declaring a char type buffer
	if (access(FIFO_NAME, F_OK) == -1)
	{
		res = mkfifo(FIFO_NAME, 0777);//creating a fifo file
		if(res != 0)//if creation of fifo fails the below code runs
		{
			fprintf(stderr, "Could not create fifo %s\n", FIFO_NAME);
			exit(EXIT_FAILURE);
		}
	}
	//getting the process id opening FIFO in O_WRONLY
	printf("Process %d opening FIFO O_WRONLY\n", getpid());
	pipe_fd = open(FIFO_NAME, open_mode);//opening the fifo
	printf("Process %d result %d\n", getpid(), pipe_fd);
	
	//opening the fifo and getting the pid
	
	if(pipe_fd != -1)
	{
		while(bytes_sent < TEN_MEG)
		//start writing into fifo file if above condition is true
		{
			res = write(pipe_fd, buffer, BUFFER_SIZE);
			if(res == -1)//if write fails run the below code
			{
				fprintf(stderr, "Write error on pipe\n");
				exit(EXIT_FAILURE);
			}
			bytes_sent += res;//inc and get next byte to be written
		}
		(void)close(pipe_fd);//close the fifo file
	}
	else
	{
		exit(EXIT_FAILURE);
	}
	printf("Process %d finished\n", getpid());//get the process id
	exit(EXIT_SUCCESS);//exit
}

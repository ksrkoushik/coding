#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()// any c program starts from this function
{
	int data_processed;//declaring integer variable
	int file_pipes[2];//declaring an array 
	const char some_data[] = "123";//declaring char type variable "some_data[]"
	pid_t fork_result;
	//declaring a signed int type variable "pid_t" representsa process id
	
	if(pipe(file_pipes) == 0)
	{
		fork_result = fork();//system call to fork
		printf("%d\n", fork_result);
		if(fork_result == (pid_t) -1)
		{
			fprintf(stderr, "Fork failure");
			exit(EXIT_FAILURE);
		}
		if(fork_result == (pid_t)0)//child begins
		{
			close(0);//child closes its std input
			dup(file_pipes[0]);//this duplicates the file des associated
			//with the read end of the pipe as file des 0, the std input
			close(file_pipes[0]);//child closing th org file des for 
			//reading from the pipe, file_pipes[0]
			close(file_pipes[1]);//bcos the child will never write to the
			//pipe, it also closes write file des, file_pipes[1]
			execlp("od", "od", "-c", (char *)0);//finally the child now 
			//has only single file des associated with the pipe;file des 0,
			// its std input
			exit(EXIT_FAILURE);
		}
		else
		{
			//parent
			close(file_pipes[0]);//closes the read descriptor
			data_processed = write(file_pipes[1], some_data, strlen(some_data));//uses the write file descriptor to write
			close(file_pipes[1]);//closes the write file descriptor
			printf("%d - wrote %d bytes\n", (int)getpid(), data_processed);
		}
	}
	exit(EXIT_SUCCESS);
}
		

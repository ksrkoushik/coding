#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

int main()
{
	const char *pipe_path = "./my_pipe";
	int pipe_fd;
	
	//open the named pipe for writing
	pipe_fd = open(pipe_path, O_WRONLY);
	
	//send the data to the server
	char message[] = "Hello Server\n";
	write(pipe_fd, message, strlen(message) + 1);
	printf("Client:Sent data to the server\n");
	
	//close the named pipe
	close(pipe_fd);

	printf("Client: Exiting....\n");
	return 0;
}

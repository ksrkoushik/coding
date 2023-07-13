#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
	const char *pipe_path = "./my_pipe";
	int pipe_fd;
	
	//create the named pipe
	mkfifo(pipe_path, 0666);
	printf("Server: Waiting for the client to connect...\n");
	
	//open the named pipe for reading
	pipe_fd = open(pipe_path, O_RDONLY);
	char data[100];
	
	//read data from named pipe
	read(pipe_fd, data, sizeof(data));
	printf("Server:Received data from the client: %s\n", data);
	
	//close the named pipe
	close(pipe_fd);

	//remove the named pipe
	unlink(pipe_path);
	printf("Server: Exiting...\n");
	
	return 0;
}


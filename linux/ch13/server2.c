#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>

#define MAX_CLIENTS 5

int main()
{
	const char *pipe_path = "./my_pipe";
    	int pipe_fd[MAX_CLIENTS];
    	int i;
	
	//create the named pipe
	mkfifo(pipe_path, 0666);

	printf("Server: Waiting for clients to connect..\n");
	//open named pipes for reading
	for (i = 0; i < MAX_CLIENTS; i++)
    	{	
        	char client_pipe[20];
        	sprintf(client_pipe, "%s%d", pipe_path, i);
        	pipe_fd[i] = open(client_pipe, O_RDONLY);
    	}	
 	//read the data from each client
 	
	for (i = 0; i < MAX_CLIENTS; i++)
    	{
        	char data[100];
        	read(pipe_fd[i], data, sizeof(data));
        	printf("Server: Received data from client %d: %s\n", i, data);
        	close(pipe_fd[i]);
    	}
	//remove the named pipes
	for (i = 0; i < MAX_CLIENTS; i++)
    	{
        	char client_pipe[20];
        	sprintf(client_pipe, "%s%d", pipe_path, i);
        	unlink(client_pipe);
    	}

	//remove the main named pipe
	unlink(pipe_path);
	printf("Server: Exiting....\n");
	return 0;
}

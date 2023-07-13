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
    	char client_pipe[20];
    	int client_id;

	printf("Enter client id(0-4): ");
	scanf("%d", &client_id);
	
	sprintf(client_pipe, "%s%d", pipe_path, client_id);
	
	//create the named pipe
	mkfifo(client_pipe, 0666);
	
	//open the named pipe for writng
	pipe_fd = open(client_pipe, O_WRONLY);
	
	//send data to the server
	char message[100];
	printf("Enter Message: ");
	scanf(" %[^\n]", message);
	write(pipe_fd, message, strlen(message) + 1);
	printf("Client %d: Sent data to the server\n", client_id);

	//close the named pipe
	close(pipe_fd);
	//remove the named pipe
	unlink(client_pipe);
	
	printf("Client %d: Exiting....\n", client_id);
	return 0;
}


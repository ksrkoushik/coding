#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

#define SERVER_FIFO_NAME "./tmp/serv_fifo"// defining a fifo filename for server
#define CLIENT_FIFO_NAME "./tmp/cli_%d_fifo"//defining a fifo file name for client
#define BUFFER_SIZE 20// defining the size of buffer
struct data_to_pass_st// creating a structure
{
	pid_t client_pid;//declaring a pid_t variable for client pid
	char some_data[BUFFER_SIZE - 1];//declaring a variable some_data to hold data
};

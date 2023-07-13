#include "client.h"
#include <ctype.h>

int main()// any c program starts from this function
{
	int server_fifo_fd, client_fifo_fd;//creating two int variables
	struct data_to_pass_st my_data;//creating a struct with name my_data
	int read_res;// declaring an int variable read_res
	char client_fifo[256];//declaring a client_fifo char type variable
	char *tmp_char_ptr;//declaring char type pointer variable
	
	mkfifo(SERVER_FIFO_NAME, 0777);//creating a named pipe fifo file
	server_fifo_fd = open(SERVER_FIFO_NAME, O_RDONLY);
	//opening the created fifo file in blocking mode with O_RDONLY
	if(server_fifo_fd == -1)
	{
		fprintf(stderr, "Server fifo failure\n");
		exit(EXIT_FAILURE);
	}
	//if fifo file does not open this above if block will be executed
	sleep(10);//if fifo successfully opens it sleeps for 10 secs(means waits)
	do
	{
		//here it tries to read the data
		read_res = read(server_fifo_fd, &my_data, sizeof(my_data));
		
		if (read_res > 0)
		{
		//assigning the captured data to a location pointed by tmp_char_ptr
			tmp_char_ptr = my_data.some_data;
			while(*tmp_char_ptr)
			{
			//here the captured data is converted to upper case
				*tmp_char_ptr = toupper(*tmp_char_ptr);
				tmp_char_ptr++;
			}
			//instead of printing , here all the data is stored in sprintf
			sprintf(client_fifo, CLIENT_FIFO_NAME, my_data.client_pid);
			//here the processed data is sent back to client
			client_fifo_fd = open(client_fifo, O_WRONLY);
			//here the clinet fifo is opened in O_WRONLY mode
			if (client_fifo_fd != -1)
			{
				write(client_fifo_fd, &my_data, sizeof(my_data));
				close(client_fifo_fd);
			}
			//as long as there is some data, the client will be written
		}
	}while (read_res > 0);//as along as read_res has data > 0 the above code runs
	close(server_fifo_fd);//once done server fifo is closed
	unlink(SERVER_FIFO_NAME);//server fifo is unlinked
	exit(EXIT_SUCCESS);//exited
}

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int data_processed;//declaring a int variable "data_processed"
	char buffer[BUFSIZ + 1];//declaring a char type variable "buffer"
	int file_descriptor;//declaring an int type "file_descriptor"
	
	memset(buffer,'\0', sizeof(buffer));//memory allocation
	sscanf(argv[1], "%d", &file_descriptor);//extracting the file descriptor no.
	data_processed = read(file_descriptor, buffer, BUFSIZ);
	//reading from the file descriptor
	
	printf("%d - read %d bytes: %s\n", getpid(), data_processed, buffer);
	exit(EXIT_SUCCESS);
}

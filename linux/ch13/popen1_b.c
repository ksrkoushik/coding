#include <stdio.h>
#include <stdlib.h>
int main()
{
	char buffer[BUFSIZ + 1];//declaring a char type variable "buffer"
	FILE *file_ptr;//creating a ptr variable "file_ptr"
	size_t bytes_read;//creating an uninsigned int data type and represents
			//the size of an object in memory
	file_ptr = fopen("../../file1.txt", "rb");// file to be opened
	if(file_ptr != NULL)
	{
		bytes_read = fread(buffer, sizeof(char), sizeof(buffer), file_ptr);
		if(bytes_read > 0)
		{
			printf("%s", buffer);
		}
		fclose(file_ptr);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

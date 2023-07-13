#include <stdio.h>
#include <stdlib.h>
int main()
{
	char buffer[BUFSIZ + 1];//declaring a character type variable "buffer"
	FILE *read_fp;//initializing a pointer variable "read_fp"
	int chars_read;//declaring an int variable "chars_read"
	read_fp = popen("ifconfig", "r");// calling popen function
	if(read_fp != NULL)
	{
		chars_read = fread(buffer, sizeof(char),BUFSIZ, read_fp);
		if(chars_read > 0)
		{		
			printf("%s", buffer);
		}
		pclose(read_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

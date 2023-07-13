#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//this program makes you to send data in smaller pieces or perhaps when you 
//dont know the size of the output.So, to avoid having to declare a very large
//buffer, this can just use multiple fread or fwrite calls and process the 
//data in parts.
int main()
{
	FILE *read_fp;//declaring a pointer variable "read_fp"
	char buffer[(BUFSIZ/10) + 1];//declaring a char type variable "buffer"
	int chars_read;//declaring int type variable chars_read
	memset(buffer, '\0', sizeof(buffer));//reserving a block of memory
	read_fp = popen("ps ax", "r");//calling a function popen
	if(read_fp !=NULL)
	{
		chars_read = fread(buffer, sizeof(char), BUFSIZ/10, read_fp);
		while(chars_read > 0)
		{
			buffer[chars_read - 1] = '\0';
			printf("Reading %d:-\n %s\n", BUFSIZ/10, buffer);
			chars_read = fread(buffer, sizeof(char), BUFSIZ/10, read_fp);
		}
		pclose(read_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

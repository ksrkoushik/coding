#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *read_fp;//declaring a ptr variable "read_fp"
	char buffer[BUFSIZ + 1];//declaring a char type variable "buffer"
	int chars_read;//declaring int type variable "chars_read"
	memset(buffer, '\0', sizeof(buffer));//allocating a block of memory
	read_fp = popen("cat popen*.c | wc -l", "r");//calling function popen
	if(read_fp != NULL)
	{
		chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		while(chars_read > 0)
		{
			buffer[chars_read - 1] = '\0';
			printf("Reading:-\n %s\n", buffer);
			chars_read = fread(buffer, sizeof(char), BUFSIZ, read_fp);
		}
		pclose(read_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

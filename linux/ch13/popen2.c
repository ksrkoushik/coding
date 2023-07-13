#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	FILE *write_fp;//declaring a ptr type variable "write_fp"
	char buffer[BUFSIZ + 1];//creating a char type variable "buffer"
	sprintf(buffer, "once upon a time, there was....\n");//stores the string
	write_fp = popen("od -c", "w");//calling the function popen
	if(write_fp != NULL)
	{
		fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
		pclose(write_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
//You can also check the same output of this program,
//when we type
//echo "Once upon a time, there was..." | od -c

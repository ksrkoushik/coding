#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main()// any c program starts with this function
{
	char *const ps_envp[] = {"PATH = /bin:/usr/bin/", 0};// passing the path argument
	printf("Running dmesg  using execle\n");// printing line of text
	execle("/bin/dmesg", "dmesg", 0, ps_envp);// executing "dmesg" from execle
	printf("Done\n");//printing a string
	return 0;// returns a value 0 if program is executed successfully
}
	

#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()// any c program starts from this function
{
	pid_t pid;// declaring pid variable pid_t
	char *message;//decalring a char type message
	int n;//declaring integer variable n
	printf("fork program starting\n");//printing a line of text
	pid = fork();//calling the function fork
	switch(pid)//using switch case statement for different pid's
	{
		case -1:// when fork fails
			perror("fork failed");
			return 1;
		case 0://when child runs
			message = "This is the child";
			n = 3;
			break;
		default://this is the default or parent case
			message = "This is the parent";
			n = 5;
			break;
	}
	for(;n>0;n--)
	{
		puts(message);
		sleep(1);
	}
	return 0;
}

//zombie or defunct process:
//This process is created if the child process is finished earlier than parent,
//although no longer the child process still remains in the system because the 
//child will have an association with its parent, hence unless and until 
//the parent process either terminates normally or calls for wait, this 
//child process will stay there as a zombie or defunct process.

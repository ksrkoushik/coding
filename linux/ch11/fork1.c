#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;// declaring function variable pid
	char *message;// string for message
	int n;// integer variable n

	printf("fork program starting\n");
	pid = fork();// calling the function fork
	switch(pid)// using switch case statements 
	{
		case -1:// this case is when fork is failed
			perror("fork failed");// perror is called when fork fails
			return 1;
		case 0:// this case is when child process is executed
			message = "This is the child";
			n = 5;
			break;
		default:// this case is when parent process is executed
			message = "This is the parent";
			n = 3;
			break;
	}
	for(;n>0;n--)
	{
		puts(message);
		sleep(1);
	}
	return 0;
}

// In this, a child is created and prints a message 5 times.The original process(parent)
// prints a message only 3 times.The parent process finishes before the child has
// printed all of its messages, so the next shell prompt appears mixed 
// in with the output.
// To overcome this problem, we can use wait command.

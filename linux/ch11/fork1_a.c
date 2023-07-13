#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
//Duplcating a process image
// "fork" + "wait" + "signal"
void  boom(int sig)// defining a function "boom" to handle any interrupt signal
{
	        printf("BOOM! - I got an interrupt signal %d\n", sig);
		// printing a line of text with interrupt signal no.
		(void) signal(SIGINT, SIG_DFL);
		// this is when press CTRL + C 2nd time, 
		// it will get into SIG_DFL mode.
}
int sum()// defining a simple function called "sum()"
{
	int a, b, c;// defining integer variables a, b and c
	printf("Please enter only integer values !!!!\n");// Printing a line of text
	scanf("%d\n%d", &a, &b);//taking the input values from the user	
	c = a + b;// adding the given integers
	printf("a = %d and b = %d, sum = %d\n", a, b, c);
	// printing the output values
	return 0;
}

int main()// any c program starts from this function
{
	(void) signal(SIGINT, boom);

	int exit_code;//defining an integer variable exit_code
	pid_t pid;//defining a pid variable
	printf("fork program is starting\n");//printing a line of text
	pid = fork();//calling the finction fork
	switch(pid)//using switch case statements to deal with the processes
	{
		case -1://this case is executed when fork fails
			perror("fork failed");
			return 1;
		case 0:// this case is the child process
			// where the call to fork returns zero
		        printf("This is a child process\n");
			//printing a line of text
		        printf("value rtn by fork inside the child is: %d\n", pid);
			// this will print the value returned by fork inside 
			// child process
			sum();//calling the function called sum
			exit_code = 50;// this is the exit code when child process
					// is finished.
			break;
		default:
			printf("This is parent process\n");// printing line of text
			printf("pid value of new process(child) is %d\n", pid);
			// printing the PID of the new process(child)
			exit_code = 0;// the call to fork in the parent returns 
					//the PID of the new child process.
			break;
	}
	if (pid!=0)
	{
		int stat_val;// declaring an integer variable
		pid_t child_pid;// defining a pid variable child_pid
		child_pid = wait(&stat_val);
		// The status infon allows the parent  process to determine
	        // the exit status of the child process, that is, the value
	        // returned from main  or passed to exit.
		 // If stat_val is not a null pointer, then the status infon 
		// will be written to the location to which it points.
		printf("pid value of the child process is %d\n", pid);
		// printing child process PID
		printf("Child has now finished: PID = %d\n", child_pid);
		// printing child process PID
		if(WIFEXITED(stat_val))
		// if WIFEXITED(stat_val) is non-zero,it means that the 
		// child process terminated normally
			printf("Child extd with code %d\n", WEXITSTATUS(stat_val));
		// If WIFEXITED is non-zero, this returns child exit code	
		else
			printf("Child terminated abnormally\n");
	}
	printf("exitcode is %d\n", exit_code);
	exit(exit_code);	
}
	




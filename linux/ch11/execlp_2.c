#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main()//any c program starts with this function
{
	printf("Running ps with execlp\n");//printing a line of text
	execlp("ps", "ps", "-ef", 0);//assumes /bin is in the path and "ps ax" command is executed
				    //inside execlp function call
	printf("Done\n");
	return 0;
}
//exec command:
//An exec function replaces the current process with a new process specified by the path or file argument.
//These exec functions are used to "hand off" execution of a program to another.
//library to be included is #include <unistd.h>
//there are six types of exec functions:
//(1) execl("/bin/ps","ps", "ax", 0); // assumes ps is in bin 
//(2) execlp("ps", "ps", "ax", 0); // assumes /bin is in path
//(3) execle("/bin/ps", "ps", "ax", 0, ps_envp);
//These above three commands take a variable number of arguments ending 
//with a null pointer.
//(4) execv("/bin/ps", ps_argv);
//(5) execvp("ps", ps_argv);
//(6) execve("/bin/ps", ps_argv, ps_envp);
//The 4th and 6th commands pass an additional argument to functions execle and execve
// for passing an array of strings to be used as the new program environment
//Passing argument strings:
//char *const ps_argv[] = {"ps", "ax", 0};//considering ps is in /bin/ps
//using environment variable
//char *const ps_envp[] = {"PATH=/bin:/usr/bin", "TERM=console", 0);

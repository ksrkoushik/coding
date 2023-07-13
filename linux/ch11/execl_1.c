#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
int main()// any c program starts from this function
{
	printf("Running pstree with execl\n");//printing a line of text
	execl("/bin/pstree", "pstree", 0);// executing "pstree" from execl
	printf("Done\n");// printing a string
	return 0;// returns a value 0 on successful execution of the program
}
// here we can observe that the "pstree" command is executed and hence
// the string "Done" is not being printed on the terminal in the output

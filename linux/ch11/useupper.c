#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])//any c program starts with this function
{
	char *filename;//declaring a char type filename
	if(argc != 2)//if the arguments passed are not two, execute the below code block
	{
		fprintf(stderr, "usage: useupper file\n");
		exit(1);
	}
	filename = argv[1];// assigning argument 1 to filename
	if(!freopen(filename,"r", stdin))//if unable to read the filename, execute 
					 //the below code block
	{
		fprintf(stderr, "could not redirect stdin from file %s\n", filename);
		exit(2);
	}
	execl("./upper", "upper", 0);//executing ./upper from inside execl function
	perror("Could not exec ./upper");//if any error calling perror function
	exit(3);
}


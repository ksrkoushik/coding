#include <stdio.h>

void line(), message();

int main()
{
	printf("Hello! The program starts in main().\n");
	line();
	message();
	line();
	printf("This is the end of main().\n");
	return 0;
}
void line()
{
	printf("--------------------\n");
}
void message()
{
	printf("In function message().\n");
}

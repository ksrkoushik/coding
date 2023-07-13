#include <stdio.h>
void pause();
int main()
{
	printf("Dear reader,\n");
	printf("have a ");
	pause();
	printf("!\n");
	return 0;
}
void pause()
{
	printf("BREAK");
}

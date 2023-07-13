#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *ptr = 3000;
	printf("Before changing %p\n", ptr);
	ptr = ptr + 1;
	printf("%p\n", ptr);
	char *ptr1 = 4000;
	printf("Before changing %p\n", ptr1);
	ptr1 = ptr1 + 1;
	printf("%p\n", ptr1);
	return 0;
}


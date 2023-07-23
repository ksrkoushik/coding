#include <stdio.h>
int main()
{
	printf("memory space of int: %d\n bytes", sizeof(int));
	printf("memory space of float: %d\n bytes", sizeof(float));
	printf("memory space of double: %d\n bytes", sizeof(double));
	printf("memory space of char: %d\n bytes", sizeof(char));
	printf("memory space of long double: %d\n bytes", sizeof(long double));
	return 0;
}

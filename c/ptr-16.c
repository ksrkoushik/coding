#include <stdio.h>
#include <stdlib.h>
int main()
{
	printf("The size of int is %d\n", sizeof(int));
	printf("the size of double is %d\n", sizeof(double));
	printf("The size of float is %d\n", sizeof(float));
	printf("The size of char is %d\n", sizeof(char));
	printf("The size of a character a is %d\n", sizeof('a'));
	printf("The size of a character a is %d\n", sizeof("a"));
	return 0;
}

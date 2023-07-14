#include <stdio.h>
#include <limits.h>
int main()
{
	printf("Range of types int and unsigned int\n");
	printf("Type               Minimum           Maximum\n");
	printf("int        %d                %d\n", INT_MIN, INT_MAX);
	printf("unsigned int        %d                 %u\n", 0, UINT_MAX);
	return 0;
}

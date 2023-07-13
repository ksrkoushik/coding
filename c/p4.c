#include <stdio.h>
int main()
{
	int a = 5, b = 7;
	printf("Before Swapping\n");
	printf("a = %d\nb = %d\n", a , b);
	int temp;
	temp = a;
	a = b;
	b = temp;
	printf("After Swapping\n");
	printf("a = %d\nb = %d\n", a, b);
	return 0;
}


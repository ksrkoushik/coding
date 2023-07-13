#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int a, b, c;
int sum()
{
	a = 100;
	b = 57;
	c = a + b;
	printf("The sum is %d\n", c);
}
int mul()
{
	a = 25;
	b = 4;
	c = a * b;
	printf("The product is %d\n", c);
}
int main(int argc, char *argv[])
{
	sum();
	mul();
	return 0;
}

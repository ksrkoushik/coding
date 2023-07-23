#include <stdio.h>
void sum(double a, double b)
{
	double c = a + b;
	printf("The sum is: %f\n", c);
}
void diff(double a, double b)
{
	double c = a - b;
	printf("The diff is: %f\n", c);
}
int main()
{
	sum(123.456, 76.543);
	diff(123.456, 76.543);
	return 0;
}


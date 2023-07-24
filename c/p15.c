#include <stdio.h>
#include <math.h>
int main()
{
	double x = 2.5, y;
	y = pow(x, 3);
	printf("2.5 raised to 3 yields: %.1f\n", y);
	printf("5 raised to power 2.5 yields: %.1f\n", pow(5, x));
	return 0;
}

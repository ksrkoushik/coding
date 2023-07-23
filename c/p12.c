#include <stdio.h>
const double pi = 3.141593;
int main()
{
	double area, circuit, radius=1.5;
	area = pi * radius * radius;
	circuit = 2 * pi * radius;
	printf("\nTo Evaluate a Circle\n");
	printf("Radius: %f\n", radius);
	printf("Circumference: %f\n", circuit);
	printf("Area: %f\n", area);
	return 0;
}

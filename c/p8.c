#include <stdio.h>
int main()
{
	double  num1, num2, num3;
	scanf("%lf\n", &num1);
	scanf("%lf\n", &num2);
	scanf("%lf", &num3);
	
	if((num1 > num2) & (num2 > num3))
	{
		printf("The max num is %.2f\n", num1);
		printf("The min num is %.2f\n", num3);
	}
	else if((num1 > num3) & (num3 > num2))
	{
		printf("The max num is %.2f\n", num1);
		printf("The min num is %.2f\n", num2);
	}
	else if((num2 > num3) & (num3 > num1))
	{
		printf("The max num is %.2f\n", num2);
		printf("The min num is %.2f\n", num1);
	}
	else if((num2 > num1) & (num1 > num3))
	{
		printf("The max num is %.2f\n", num2);
		printf("The min num is %.2f\n", num3);
	}
	else if((num3 > num1) & (num1 > num2))
	{
		printf("The max num is %.2f\n", num3);
		printf("The min num is %.2f\n", num2);
	}
	else if((num1 == num2) & (num2 == num3))
	{
		printf("All numbers are equal\n");
	}
	
	return 0;
}

		        


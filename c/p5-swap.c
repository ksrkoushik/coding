#include <stdio.h>
void swap(int num1, int num2)
{
	int temp;
	printf("Before Swapping num1 = %d and num2 = %d\n", num1, num2);
	temp = num1;
	num1 = num2;
	num2 = temp;
	printf("After swapping num1 = %d and num2 = %d\n", num1, num2);
}
int main()
{
	swap(5,7);
	return 0;
}


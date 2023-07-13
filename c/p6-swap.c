#include <stdio.h>
void swap(int num1, int num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}
int main()
{
	int a = 5, b = 7;
	printf("Before Swapping a = %d and b = %d\n", a, b);
	swap(a,b);
	printf("After Swapping a = %d and b = %d\n", a, b);
	return 0;
}

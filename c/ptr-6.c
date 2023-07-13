#include <stdio.h>
#include <stdlib.h>
int main()// any c program starts with this function
{
	int num1 = 5, num2 = 7;//declaring and initializing variables
	int *ptr1, *ptr2;//initialization of pointer variables
	printf("num1 = %d, num2 = %d\n", num1,num2);// guess the output
	ptr1 = &num1;//assigning address of num1
	ptr2 = &num2;//assigning address of num2
	printf("num1 = %d, num2 = %d\n", num1,num2);//guess the output
	*ptr1 = *ptr1 + 1;// guess what's happening here
	*ptr2 = *ptr2 + 3;// guess what's happening here
	printf("num1 = %d, num2 = %d\n", num1, num2);//guess the output
	ptr1 = ptr2;// what's happening here
	ptr2 = ptr1;//what's happening here
	printf("num1 = %d, num2 = %d\n", num1, num2);//guess the output
	printf("*ptr1 = %d, *ptr2 = %d\n", *ptr1, *ptr2);//guess the output
	num2 = *ptr1;// guess what's happening
	num1 = num2 + 5;// guess what's happening
	printf("num1 = %d, num2 = %d\n", num1, num2);// guess the output
	return 0;
}

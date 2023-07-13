#include <stdio.h>
#include <stdlib.h>
int findMax(int num1, int num2)// function for finding max num
{
	if(num1 > num2)
		return num1;
	else
		return num2;
	
}

int findMin(int num1, int num2)// function for finding min num
{
	if(num1 > num2)
		return num2;
	else
		return num1;
}

int  main()//any c program starts from this function
{
	int a = 5, b = 7;// declaring and initializing variables
	int max, min;//declaring variables
	int *ptr1, *ptr2;//declaring pointer variables
	ptr1 = &a;// passing address of 'a' to pointer ptr1
	ptr2 = &b;// passing address of 'b' to pointer ptr2
	max = findMax(*ptr1, *ptr2);//calling the function with args *ptr1, *ptr2
	min = findMin(*ptr1, *ptr2);// calling the function with args *ptr1, *ptr2
	printf("maximum between %d and %d = %d\n",a,b,max);
	printf("minimum between %d and %d = %d\n",a,b,min);
	*ptr1 = *ptr1 + 100;// adds 100 to variable 'a' indirectly through *ptr1
	*ptr2 = *ptr2 * 5;// adds 5 to variable 'b' indirectly through *ptr2
	max = findMax(*ptr1, *ptr2);//again calling the function
	min = findMin(*ptr1, *ptr2);//again calling the function
	printf("After pointers updating the values of a and b\n");
	printf("maximum between %d and %d = %d\n", a,b,max);
	printf("maximun between %d and %d = %d\n", a,b,min);
	return 0;
}
	

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int num1, num2;
	int *ptr1;
	ptr1 = &num1;
	
	int *ptr2 = (int *) malloc(sizeof(float)); 
	ptr2 = &num2;

	int marks[] = {35, 47, 55, 25, 77};
	int *ptr3 = marks;
	int k = sizeof(marks)/sizeof(int);
	int n;
	*ptr1 = 500;
	*ptr2 = 800;
	
	printf("The value stored in num1 is %d\n", *ptr1);
	printf("The value stored in num2 is %d\n", *ptr2);
	//Printing using pointers
	printf("This is using pointers\n");
	for(n=0;n<k;n++)
	{
		printf("The value at %d is %d\n", n, *(ptr3 + n));
	}
	//Printing using arrays and indices
	printf("This is using arrays and indices\n");
	for(n=0;n<k;n++)
	{
		printf("The value at %d is %d\n", n, marks[n]);
	}
	return 0;
}

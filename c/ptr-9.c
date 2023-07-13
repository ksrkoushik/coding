#include <stdio.h>
#include <stdlib.h>

int main()// any c program starts from this function
{
	int i;
	int *ptr;//declaring a pointer variable
	int grades[3] = {80,90,100};// an array
	printf("grades start at: %p\n", grades);// prints the address of the first
						// mem location of array grades
	printf("grades : %d\n", *grades);// this will print the first value
					// even though the index is not given
	printf("grades start at : %p\n", grades+1);// pointer arithmetic
	printf("the value inc by : %d\n", *grades+1);// normal arithmetic
	for(i = 0; i<3; i++)
	{
		printf("grades: %p\n", &grades[i]);//prints the address 
		printf("grades: %d\n", grades[i]);//prints the value
	}
	return 0;
}

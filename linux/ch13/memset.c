#include <stdio.h>
#include <string.h>

//this program is used to understand the memset function
int main()//any c program starts from this function
{
	int arr[10];//declaring an integer array
	memset(arr, 0, sizeof(arr));
	//memset fn is commonly used to initialize a block of memory
	//to zero or to a specific value.
	//void *memset(void *ptr, int value, size_t num);
	//memset fn operates on a block of memory at the byte level
	//so it is commonly used with types that are a multiple of byte,
	//such as 'char', 'int', 'long'.
	//And also the num parameter should not exceed the size of the mem 
	//block pointed to by ptr. 
	int i;
	for(i=0; i<10; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}

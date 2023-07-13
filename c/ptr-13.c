#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[] = {125,45,76,88,95};
	int *marks = a;// declaring and initializing a ptr to arr
	printf("%p\n", marks);// accessing the initial address of marks array
	printf("%p\n", &marks[0]);//accessing the initial address with symbols
				// & and index
	printf("%d\n", *marks);// accessing the value with ptr
	printf("%d\n", marks[0]);//accessing the value with array and index
	int n;
	printf("%ld\n", sizeof(marks));
	printf("%ld\n", sizeof(int));
	n = sizeof(marks)/(2*sizeof(int));
	printf("%d\n", n);
	for(n=0;n<5;n++)
	{
		printf("the value at %d is %d\n",n, *(marks + n));
	}
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int temps[] = {44,34,35,46,43};
	int *ptr1 = temps;
	int k = sizeof(temps)/sizeof(int);
	printf("Total size of int is %ld\n", sizeof(int));
	printf("Total size of array is %ld\n", sizeof(temps));
	printf("The value of k is %d\n", k);
	int n;
	for(n=0;n<k;n++)
	{
		printf("The value at %d is %d\n", n, *(ptr1 +n));
	}
	return 0;
}

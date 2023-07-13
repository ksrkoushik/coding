#include <stdio.h>
#include <stdlib.h>
int main()
{
	int *ptr1;
	int grade1 = 80;
	ptr1 = &grade1;
	char *ptr2;
	char grade2[] = {'A', 'M'};
	ptr2 = grade2;
	double *ptr3;
	double grade3 = 90;
	ptr3 = &grade3;
	printf("%ld\n", sizeof(ptr1));
	printf("%d\n", *ptr1);
	printf("%ld\n", sizeof(ptr2));
	printf("%c\n", *ptr2);
	printf("%c\n", *(ptr2 + 1));
	printf("%ld\n", sizeof(ptr3));
	printf("%.2f\n", *ptr3);
	return 0;
}
	

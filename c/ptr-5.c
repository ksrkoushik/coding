#include <stdio.h>
#include <stdlib.h>
int main()// any c program starts from this function
{
	int grade1 = 80;// declaring an integer variable
	int grade2 = 100;// declaring an integer variable
	int *p1;// creating a pointer variable 'p1'
	int *p2;// creating a pointer variable 'p2'
	p1 = &grade1;// pointer 'p1' holding the address of grade1
	p2 = &grade2;// pointer 'p2' holding the address of grade2
	*p1 = 95;// declaring an integer value at the mem loc pointed by p1
	*p2 = 99;// declaring an integer value at the mem loc pointed by p2
	printf("%p\n", p1);//printing the address where p1 is pointing to
	printf("%p\n", &grade1);// printing the address of grade1
	printf("%d\n", grade1);// printing the value of grade1 directly
	printf("%d\n", *p1);// printing the value of grade1 indirectly
	printf("%d\n", grade2);// printing the value of grade2 directly
	printf("%d\n", *p2);// printing the value of grade2 indirectly
	
	return 0;
}

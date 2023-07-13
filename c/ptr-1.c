#include <stdio.h>
int main()//any c program starts with this function
{
	int a = 7;//declaring an integer variable
	int *p;// pointer pointing towards an integer
	p = &a;// assigning address of 'a' to pointer 'p'
	printf("value of a is %d\n", a);//getting the value of a
	printf("address of a is %p\n", &a);// getting the address of variable 'a'
	printf("%p\n", p);// getting the address where the pointer is pointing to
	printf("%d\n", *p);// accessing the value of the variable indirectly
	return 0;
}

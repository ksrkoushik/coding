#include <stdio.h>
#include <stdlib.h>
// Program about Pointer Dereferncing
int main()// any c program starts from this function
{
	int a;// creating an integer variable 'a'
	int *p;// creating a pointer variable 'p'
	p = &a;//pointer storing the address of 'a'
	*p = 5;// pointer 'p' changing the value of 'a' to 5
	printf("%d\n", a);// printing the value of 'a'
	printf("%d\n", *p);//printing the value of 'a' indirectly using ptr 'p'
	*p =  100;// again changing the value of 'a' using ptr 'p'
	printf("%d\n", a);// printing the new value of 'a'
	printf("%d\n", *p);// printing the new value of 'a'
	return 0;
}

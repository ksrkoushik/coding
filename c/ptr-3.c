#include <stdio.h>
#include <stdlib.h>
int main()// any c program starts with this function
{
	int a;// declaring integer variable 'a'
	int *p = NULL;// declaring and initializing a pointer variable
	printf("now this will have garbage value: %ls\n", p);// garbage value
	p = &a;//address of variable 'a'
	printf("%p: this is the actual addr of int variable a the  ptr pointing\n",p);	    return 0;
}

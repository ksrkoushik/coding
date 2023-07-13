#include <stdio.h>
#include <stdlib.h>
int main()// any c program starts from this func
{
	int num = 30;//declaring an int variable num
	int *p;// declaring a pointer vaiable p
	printf("%d\n", num);// prints out the value 30
	p = &num;//passing the address of variable num to pointer p
	printf("decimal rep of mem address is %d\n", &num);
	//prints the decimal representation of mem addr
	printf("decimal rep of mem address is %d\n", p);
	//prints the decimal representation of mem addr
	printf("hexadec rep of mem address is %p\n", &num);
	//prints the hexadec representation of mem addr
	printf("hexadec rep of mem address is %p\n", p);
	//prints the hexadec representation of mem addr
	*p = 20;//assigning or replacing the prev value holding by num variable
	printf("%d\n", num);//prints out the value 20
	printf("%d\n", *p);//prints out the value 20
	return 0;
}

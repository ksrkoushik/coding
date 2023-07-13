#include <stdio.h>
#include <stdlib.h>
int main()// any c program starts with this function
{
	int a = 8;// integer type variable holding a value 8
	float b = 8.0;// float type variable holding a value 8.0
	double c = 14.25;// double type variable holding a value 14.25
	char msg[16] = "Hello world";// character type variable holding a string
	int *p1;// creating a ptr p1 which points to an address of int variable
	float *p2;// creating a ptr p2 which points to an address of float variable
	double *p3;// creating a ptr p3 which points to an address of double variable
	char (*p4)[16];// creating a ptr p4 which points an address of string array
	p1 = &a;// address of 'a' stored in ptr p1
	p2 = &b;// address of 'b' stored in ptr p2
	p3 = &c;// address of 'c' stored in ptr p3
	p4 = &msg;// address of 'msg' stored in ptr p4

	printf("%d\n", a);
	printf("%d\n", *p1);
	printf("%.2f\n", b);
	printf("%.2f\n", *p2);
	printf("%f\n", c);
	printf("%f\n", *p3);
	printf("%s\n", msg);
	printf("%s\n", *p4);
	return 0;
}

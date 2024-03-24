# include <stdio.h>
int main(int argc, char *argv[])
{
	char a,b,c;
	a = 100;
	b = 0x10; //x is hexadec
	//suppose b = 010, it will be octal
	// if b = 'A', then it takes ASCII value
	c = a+b;
	printf("%d\n", c);
	return 0;
}

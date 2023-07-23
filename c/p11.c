#include <stdio.h>
int gVar1;
int gVar2 = 2;

int main()
{
	char ch = 'A';
	printf("Value of gVar1: %d\n", gVar1);
	printf("Value of gVar2: %d\n", gVar2);
	printf("Character in ch: %c\n", ch);

	int sum, number = 3;
	sum = number + 5;
	printf("Value of sum: %d\n", sum);
	return 0;
}

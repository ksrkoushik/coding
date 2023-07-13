#include <stdio.h>
void even_odd(int num)
{
	if(num %2 != 0)
	{
		printf("The number is odd\n");
	}
	else
	{
		printf("The number is even\n");
	}
}

int main()
{
	int a;
	scanf("%d", &a);
	even_odd(a);
	return 0;
}

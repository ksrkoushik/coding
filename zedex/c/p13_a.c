#include <stdio.h>
int main(int argc, char* argv[])
{
	int i, total=0;
	for(i=1;i<=10;i++)
	{
		total+=i;
	}
	printf("The sum of first 10 numbers is %d\n", total);
	return 0;
}

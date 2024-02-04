#include <stdio.h>
int main(int argc, char* argv[])
{
	int i = 0;
	while (i < 25)
	{
		printf("%d", i);
		i++;
	}
	printf("\n");
	while (i > 0)
	{
		i--;
		printf("%d", i);
		if(i == 10)
		{
			break;
		}
		else
		{
			continue;
		}
	}
	printf("\n");
	return 0;
}

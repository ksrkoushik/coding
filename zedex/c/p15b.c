#include <stdio.h>
int main(int argc, char *argv[])
{
	char *emp[] = {"Sri", "Ravi", "Venkat"};
	int sal[] = {45000, 56000, 76000};

	int count = sizeof(sal)/sizeof(int);
	int i = 0;

	for (i = 0; i < count; i++)
	{
		printf("%s %d\n", *(emp + i), *(sal + i));
	}
	printf("---\n");
	for (i = 0; i < count; i++)
	{
		printf("%s %d\n", emp[i], sal[i]);
	}
	return 0;
}

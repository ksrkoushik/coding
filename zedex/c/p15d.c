#include <stdio.h>

int main(int argc, char *argv[])
{
	char *names[] = {"Koushik", "Kumar"};
	int marks[] = {67, 99};

	int count = sizeof(marks)/sizeof(int);
	int i = 0;
	for (i = 0; i < count; i++)
	{
		printf("%p %s\n", (char *)names + i, *(names + i));
		printf("%p %d\n", (int *)marks + i, *(marks + i));
	}
	printf("---\n");
	//Another way
	for (i = 0; i < count; i++)
	{
		printf("%p %s\n", (void *)names + i, *(names + i));
		printf("%p %d\n", (void *)marks + i, *(marks + i));
	}
	return 0;
}

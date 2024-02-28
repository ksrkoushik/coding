#include <stdio.h>

int main(int argc, char *argv[])
{
	char *names[] = {"Sachin", "Dravid", "Sehwag", "Laxman"};
	int scores[] = {47, 87, 89, 99};

	int count = sizeof(scores)/sizeof(int);
	int i = 0;
	for (i = 0; i < count; i++)
	{
		printf("%s %d\n", *(names + i), *(scores + i));
	}
	printf("---\n");
	for (i = 0; i < count; i++)
	{
		printf("%s %d\n", names[i], scores[i]);
	}
	return 0;
}

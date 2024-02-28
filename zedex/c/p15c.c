#include <stdio.h>

int main(int argc, char *argv[])
{
	char *actor[] = {"Chiru", "Pawan", "Nag"};
	int package[] = { 100000, 200000, 150000};

	int count = sizeof(package)/sizeof(int);
	int i = 0;

	for (i = 0; i < count; i++)
	{
		printf("%s %d\n", *(actor + i), *(package + i));
	}
	printf("---\n");

	for (i = 0; i < count; i++)
	{
		printf("%s %d\n", actor[i], package[i]);
	}
	return 0;
}

#include <stdio.h>
int main(int argc, char* argv[])
{
	char* names[] = {"Sri", "Vish", "Dhruv"};
	int scores[] = {55, 67, 88};
	int i;
	for (i = 0; i < 3; i++)
	{
		printf("Name is %s and score is %d\n", names[i], scores[i]);
	}
	return 0;
}


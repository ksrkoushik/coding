#include <stdio.h>
#include <stdlib.h>
int main()
{
	int seed, z1, z2, z3;
	printf("..........Random Numbers.......\n");
	printf("To Initialize the random generator number\n");
	printf("\nPlease enter an integer value: ");
	scanf("%d", &seed);
	srand(seed);
	
	z1 = rand();
	z2 = rand();
	z3 = rand();
	printf("\nThree Random numbers: ");
	printf("z1 : %d z2: %d z3: %d\n", z1, z2, z3);
	return 0;
}



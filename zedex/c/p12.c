#include <stdio.h>
int main(int argc, char* argv[])
{
	int areas[] = {10, 12, 13, 14, 20};
	// three diff ways of creating arrays to store strings
	char name[] = "Zed";
	char full_name[] = {'Z', 'e', 'd', ' ', 'A', '.', 'S', 'h', 'a', 'w','\0'};
	char* new_name = "Koushik";
	//calculation of sizes
	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of areas (int[]): %ld\n", sizeof(areas));
	printf("The number of ints in areas: %ld\n", sizeof(areas)/sizeof(int));
	printf("The first area is %d, 2nd area is %d.\n", areas[0], areas[1]);
	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of name (char[]): %ld\n", sizeof(name));
	printf("The number of chars: %ld\n", sizeof(name)/sizeof(char));
	printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
	printf("The number of chars: %ld\n", sizeof(full_name)/sizeof(char));
	printf("The size of new_name (char[]): %ld\n", sizeof(new_name));
	printf("the number of chars: %ld\n", sizeof(new_name)/sizeof(char));
	printf("name=\"%s\" and full_name =\"%s\" and new_name =\"%s\"\n", name, full_name, new_name);
	return 0;
}

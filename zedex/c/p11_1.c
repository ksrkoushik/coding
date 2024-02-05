#include <stdio.h>
int main(int argc, char* argv[])
{
	int numbers[4] = {0};
	char name[4] = {'a'};
	printf("numbers: %d %d %d %d\n", numbers[0], numbers[1], numbers[2], numbers[3]);
	printf("names: %c %c %c %c\n", name[0], name[1], name[2], name[3]);
	char* new_name = "Koushik";
	printf("%ld\n", sizeof(new_name));
	printf("%s\n", new_name);
	int new_array[] = {1,2,3,4};
	printf("%d\n", new_array[0]);
	printf("%ld\n", sizeof(new_array));
	return 0;
}

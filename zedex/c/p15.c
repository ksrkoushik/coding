#include <stdio.h>

int main(int argc, char *argv[])
{
	//create some arrays
	int ages[] = {23, 35, 46, 89, 4};
	char *names[] = {"Sri", "Venky", "Ravi", "Tom", "Jerry"};
	char *sports[] = {"Cricket", "Volleyball", "Football", "Hockey", "Chess"};
	//safely get the size of ages
	int count = sizeof(ages) / sizeof(int);
	int i = 0;
	// first way of using indexing
	for (i = 0 ; i < count; i++)
	{
		printf("%s is %d years old and loves to play %s \n", names[i], ages[i], sports[i]);

	}
	
	printf ("---\n");

	// set up the pointer to the start of the arrays
	int *cur_age = ages;
	char **cur_name = names;

	//second way of using pointers
	for (i = 0; i < count; i++)
	{
		printf("%s is %d years old. \n", *(cur_name + i), *(cur_age + i));
	}
	printf("---\n");

	//third way of using pointers
	for (i = 0; i < count; i++)
	{
		printf("%s is %d years old again. \n", cur_name[i], cur_age[i]);
	}
	printf("---\n");

	//fourth way of using pointers
	for (cur_name = names, cur_age = ages; (cur_age - ages) < count; cur_name++, cur_age++)
	{
		printf("%s lived %d years so far.\n", *cur_name, *cur_age);
	}
	return 0;
}


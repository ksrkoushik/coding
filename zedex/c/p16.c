#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, int height, int weight)
{
	//malloc asks the OS to give a piece of raw memory
	// Passing sizeof(struct Person) to malloc calculates the total size of the structure
	// given all the fields inside it.
	struct Person *who = malloc(sizeof(struct Person));
	//assert is basically checking whether the malloc is done properly and it is not returning any bad value
	assert(who != NULL);
	// x -> y is kind of referencing 
	// strdup function actually is like malloc, and copies the original string into the memory it creates.
	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;
	return who;
}

void Person_destroy(struct Person *who)
{
	//making sure we dont get bad input
	assert(who != NULL);
	//free is used to return the memory we got with malloc and strdup
	//If we dont do this, we get a memory leak..
	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	struct Person *joe = Person_create("Joe Alex", 32, 64, 168);
	struct Person *frank = Person_create("Frank Blank", 20, 72, 180);
	
	printf("Joe is at memory location %p:\n", joe);
	Person_print(joe);

	printf("Frank is at memory location %p:\n", frank);
	Person_print(frank);

	joe->age += 20;
	joe->height -= 2;
	joe->weight += 40;
	Person_print(joe);

	frank->age += 20;
	frank->weight += 20;
	Person_print(frank);

	Person_destroy(joe);
	Person_destroy(frank);
	return 0;
}




































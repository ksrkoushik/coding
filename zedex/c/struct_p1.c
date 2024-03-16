#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//first define struct variables using method-I
struct House
{
	char *name;
	int cost;
};

//second define struct variables using method-II
struct Home
{
	char name[20];
	int cost;
};


// first create a stucture using method-I
struct House *House_create(char *name, int cost)
{
	struct House *which = malloc(sizeof(struct House));
	assert(which != NULL);
	which->name = malloc(strlen(name) + 1);
	assert(which->name != NULL);
	strncpy(which->name, name, strlen(name) + 1);
	which->cost = cost;
	return which;
}

void House_details(struct House *which)
{
	printf("The house name is: %s\n", which->name);
	printf("The house cost is: %d\n", which->cost);
}


int main(int argc, char *argv[])
{
	struct House *House1 = House_create("Vrindavan Apt", 3500000);
	House_details(House1);
	struct Home Home_1;
	strncpy(Home_1.name, "Sree Nivasam Apt", sizeof(Home_1.name) - 1);
	Home_1.name[sizeof(Home_1.name)+1] = '\0';
	Home_1.cost = 5000000;
	printf("The home name is %s\n", Home_1.name);
	printf("The home cost is %d\n", Home_1.cost);
	return 0;
}



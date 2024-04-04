#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Car
{
	char *name;
	int cost;
};

struct Vehicle
{
	char name[20];
	int cost;
};

struct Car *Car_create(char *name, int cost)
{
	struct Car *which = malloc(sizeof(struct Car));
	assert(which != NULL);
	which->name = strdup(name);
	which->cost = cost;
	return which;
}

void Car_print(struct Car *which)
{
	printf("Car name is %s\n", which->name);
	printf("Car cost is %d\n", which->cost);
}


int main(int argc, char *argv[])
{
	struct Car *hyundai = Car_create("Hyundai-i10", 500000);
	Car_print(hyundai);
	struct Vehicle Tata;
	strncpy(Tata.name, "Nexon", sizeof(Tata.name)-1);
	Tata.name[sizeof(Tata.name) + 1] = '\0';
	Tata.cost = 1000000;
	printf("Vehicle name is %s\n", Tata.name);
	printf("Vehicle cost is %d\n", Tata.cost);
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct Vehicle
{
	char *name;
	int cost;
};

struct Veh
{
	char name[20];
	int cost;
};

//Method-I
struct Vehicle *Vehicle_create(char *name, int cost)
{
	struct Vehicle *This = malloc(sizeof(struct Vehicle));
	assert(This != NULL);
	This->name = malloc(strlen(name) + 1);
	assert(This->name != NULL);
	strncpy(This->name, name, strlen(name) + 1);
	This->cost = cost;
	return This;
}

void Vehicle_data(struct Vehicle *This)
{
	printf("Vehicle name: %s\n", This->name);
	printf("Vehicle cost: %d\n", This->cost);
}

int main(int argc, char *argv[])
{
	//Method-I
	struct Vehicle *Vehicle_1= Vehicle_create("Tata", 600000);
	Vehicle_data(Vehicle_1);

	//Method-II
	struct Veh Vehicle1;
	strncpy(Vehicle1.name, "Hyundai", sizeof(Vehicle1.name) - 1);
	Vehicle1.name[sizeof(Vehicle1.name) - 1] = '\0';
	Vehicle1.cost = 700000;
	printf("Vehicle name: %s\n", Vehicle1.name);
	printf("Vehicle cost: %d\n", Vehicle1.cost);
	return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Department
{
	char *name;
	int expenses;
};

struct College
{
	char name[30];
	int rank;
};

struct Department *Department_create(char *name, int expenses)
{
	struct Department *which = malloc(sizeof(struct Department));
	assert(which != NULL);
	which->name = malloc(strlen(name)+ 1);
	assert(which->name != NULL);
	strncpy(which->name, name, strlen(name)+1);
	which->expenses = expenses;
	return which;
}

void Dep_details(struct Department *which)
{
	printf("The Dept name is %s\n", which->name);
	printf("The Dept expenses is %d rupees\n", which->expenses);
}

int main(int argc, char *argv[])
{
	struct Department *Dept1 = Department_create("ECE", 150000);
	Dep_details(Dept1);
	//another struct without using pointers
	struct College college1;
	strncpy(college1.name, "NIT Warangal", sizeof(college1.name)-1);
	college1.name[sizeof(college1.name) + 1] = '\0';
	college1.rank = 1;
	printf("The college name is %s\n", college1.name);
	printf("The rank of the college is %d\n", college1.rank);
	return 0;
}

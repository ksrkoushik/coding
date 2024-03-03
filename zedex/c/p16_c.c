#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Emp
{
	char *name;
	int Sal;
};

struct Emp *Emp_create(char *name, int Sal)
{
	struct Emp *who = malloc(sizeof(struct Emp));
	assert(who != NULL);
	who->name = malloc(strlen(name) + 1);
	assert(who->name != NULL);
	strncpy(who->name, name, strlen(name) + 1);
	who->Sal = Sal;
	return who;
}

void Emp_data(struct Emp *who)
{
	printf("Emp-Name: %s\n", who->name);
	printf("Emp-Salary: %d\n", who->Sal);
}

void Emp_destroy(struct Emp *who)
{
	assert(who != NULL);
	free(who->name);
	free(who);
}


// Another way dealing with Struct without the use of pointers
struct Comp
{
	char name[30];
	int revenue;
};

int main(int argc, char *argv[])
{
	struct Emp *Arun = Emp_create("Arun", 65000);
 	Emp_data(Arun);
	Emp_destroy(Arun);	
	
	//This is another way of struct
	struct Comp Company1;
	strncpy(Company1.name, "Airtel", sizeof(Company1.name) - 1);
	Company1.name[sizeof(Company1.name) - 1] = '\0';
	Company1.revenue = 300000;
	printf("Company-Name: %s\n", Company1.name);
	printf("Company-Revenue: %d\n", Company1.revenue);
	return 0;
}









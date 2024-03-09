#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct Emp
{
	char *name;
	int Sal;
};

struct Player
{
	char *name;
	int cost;
};

struct Player *Player_create(char *name, int cost)//it is a fn signature, declares a fn named Player_create and returns a ptr to struct
{
	struct Player *whom = malloc(sizeof(struct Player));//allocating mem to struct, ptr to allocated mem is stored in variable whom
	assert(whom != NULL);//checks if mem allocation is successful
	whom->name = malloc(strlen(name) + 1);//allocates enough mem to hold the string with one addl byte for null terminaltor
	assert(whom->name != NULL);//checks if mem allocation is successful
	strncpy(whom->name, name, strlen(name) + 1);//copies string name into name attribute of player object including null terminator
	whom->cost = cost;//sets the cost attribute of the player object to the value passed to the cost
	return whom;//fn returns a ptr to the newly created struct Player object
}

void Player_database(struct Player *whom)
{
	printf("Player name: %s\n", whom->name);
	printf("Player cost: %d\n", whom->cost);
}
        	
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
	struct Comp Company1;//declares a variable Company1 of type struct Comp
	strncpy(Company1.name, "Airtel", sizeof(Company1.name) - 1);//sizeof is ensuring to prevent buffer overflow
	Company1.name[sizeof(Company1.name) - 1] = '\0';//appending a null terminator at the end of the string name
	Company1.revenue = 300000;//sets the revenue attribute with a value
	printf("Company-Name: %s\n", Company1.name);
	printf("Company-Revenue: %d\n", Company1.revenue);

	struct Player *player1 = Player_create("Sachin", 500000);
	Player_database(player1);
	return 0;
}









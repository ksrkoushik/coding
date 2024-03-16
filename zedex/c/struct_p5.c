#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct network
{
	char *name;
	int num_users;
};

struct nw
{
	char name[20];
	int no_users;
};

struct network *network_create(char *name, int num_users)
{
	struct network *which = malloc(sizeof(struct network));
	assert(which != NULL);
	which->name = malloc(strlen(name) + 1);
	assert(which->name != NULL);
	strncpy(which->name, name, strlen(name)+1);
	which->name = name;
	which->num_users = num_users;
	return which;
}

void network_data(struct network *which)
{
	printf("The network name is %s\n", which->name);
	printf("The number opf users are %d\n", which->num_users);
}

int main(int argc, char *argv[])
{
	struct network *network1 = network_create("Facebook", 200000);
	network_data(network1);
	//another way
	struct nw nw1;
	strncpy(nw1.name, "Twitter", sizeof(nw1.name) - 1);
	nw1.name[sizeof(nw1.name) + 1] = '\0';
	nw1.no_users = 100000;
	printf("The nw name is %s\n", nw1.name);
	printf("The number of users are %d\n", nw1.no_users);
	return 0;
}

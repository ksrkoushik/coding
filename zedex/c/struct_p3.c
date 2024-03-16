#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct sports
{
	char *name;
	int num_players;
};

struct games
{
	char name[20];
	int no_players;
};

struct sports *sports_create(char *name, int num_players)
{
	struct sports *This = malloc(sizeof(struct sports));
	assert(This != NULL);
	This->name = malloc(strlen(name) + 1);
	assert(This->name != NULL);
	strncpy(This->name, name, strlen(name) + 1);
	This->name = name;
	This->num_players = num_players;
	return This;
}

void sports_data(struct sports *This)
{
	printf("The sport name is %s\n", This->name);
	printf("The number of players required is %d\n", This->num_players);
}

int main(int argc, char *argv[])
{
	struct sports *sport1 = sports_create("Cricket", 11);
	sports_data(sport1);
	//another way
	struct games game1;
	strncpy(game1.name, "Chess", sizeof(game1.name)-1);
	game1.name[sizeof(game1.name) + 1] = '\0';
	game1.no_players = 2;
	printf("The game name is %s\n", game1.name);
	printf("The no. of players required is %d\n", game1.no_players);
	return 0;
}

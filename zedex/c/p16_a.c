#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

struct Player
{
	char *name;
	int runs_scored;
};

struct Player *Player_create(char *name, int runs_scored)
{
	struct Player *who = malloc(sizeof(struct Player));
	assert(who != NULL);
	who->name = malloc(strlen(name) + 1);
	assert(who->name != NULL);
	strncpy(who->name, name, strlen(name) + 1);
	who -> runs_scored = runs_scored;
	return who;
}

void Player_print(struct Player *who)
{
	printf("Name: %s\n", who -> name);
	printf("Runs: %d\n", who -> runs_scored);
}

void Player_destroy(struct Player *who)
{
	assert(who != NULL);
	free(who -> name);
	free(who);
}

int main(int argc, char *argv[])
{
	struct Player *Sachin = Player_create("Sachin Tendulkar", 157);
	printf("Sachin is at memory location %p\n", Sachin);
	Player_print(Sachin);

	struct Player *Dravid = Player_create("Rahul Dravid", 165);
	printf("Dravid is at memory location %p\n", Dravid);
	Player_print(Dravid);

	Player_destroy(Sachin);
	Player_destroy(Dravid);
	return 0;
}











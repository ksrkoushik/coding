#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct movies
{
	char *name;
	int num_released;
};

struct films
{
	char name[20];
	int no_released;
};

struct movies *movie_create(char *name, int num_released)
{
	struct movies *who = malloc(sizeof(struct movies));
	assert(who != NULL);
	who->name = malloc(strlen(name) + 1);
	assert(who->name != NULL);
	strncpy(who->name, name, strlen(name) + 1);
	who->num_released = num_released;
	return who;
}

void movie_data(struct movies *who)
{
	printf("The movie name is %s\n", who->name);
	printf("The %s movie is released in %d theatres all over the world\n", who->name, who->num_released);
}

int main(int argc, char *argv[])
{
	struct movies *movie1 = movie_create("Hanuman", 897);
	movie_data(movie1);
	//another way
	struct films film1;
	strncpy(film1.name, "Bahubali", sizeof(film1.name) - 1);
	film1.name[sizeof(film1.name) + 1] = '\0';
	film1.no_released = 2100;
	printf("The film name is %s\n", film1.name);
	printf("The %s film released in %d theatres through out the world.\n", film1.name, film1.no_released);
	return 0;
}

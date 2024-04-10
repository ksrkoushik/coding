#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
        struct Team
        {
                char *names;
                int cost;
        };

        struct Team *Player;
	Player = (struct Team *)malloc(sizeof(struct Team));
        Player->names = "Sachin";
	Player->cost = 100000;
	printf("size of struct Team Player is %ld\n", sizeof(Player));
	printf("Player name is %s and the cost is %d\n", Player->names, Player->cost);
	free(Player);
	return 0;
}


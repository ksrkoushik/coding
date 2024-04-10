#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	//this is a struct data type
	struct xyz
	{
		char x;// 1 byte
		short y;// 2 bytes
		char a;//1 byte
		long z;//8 byte
	};

	//this is a struct variable
	struct xyz abc;
	abc.x = 10;
	abc.y = 20;
	abc.a = 30;
	abc.z = 40;
	printf("memory size allocated is %ld\n", sizeof(abc));
	printf("%ld %ld %ld %ld\n", &abc.x, &abc.y, &abc.a, &abc.z);
	printf("%d %d %d %d\n", abc.x, abc.y, abc.a, abc.z);

	//this is another way of struct pointer variable
	struct xyz *def;
	def = (struct xyz *)malloc(sizeof(struct xyz));
	def->x = 10;
	def->y = 200;
	def->a = 30;
	def->z = 400;
	printf("memory size allocated is %ld\n", sizeof(*def));
	printf("%ld %ld %ld %ld\n", &def->x, &def->y, &def->a, &def->z);
	printf("%d %d %d %ld\n", def->x, def->y, def->a, def->z);

	//Another way of using struct pointer variable
	(*def).x = 10;
	(*def).y = 500;
	(*def).a = 15;
	(*def).z = 600;
	printf("memory size allocated is %ld\n", sizeof(*def));
	printf("%ld %ld %ld %ld\n", &(*def).x, &(*def).y, &(*def).a, &(*def).z);
	printf("%d %d %d %ld\n", (*def).x, (*def).y, (*def).a, (*def).z);
	free(def);

	//Array of Structures
	struct xyz sys[20];
	sys[0].x = 20;
	sys[0].y = 250;
	sys[0].a = 11;
	sys[0].z = 700;
	printf("memory size allocated is %ld\n", sizeof(sys[20]));
	printf("%ld %ld %ld %ld\n", &(sys[0].x), &(sys[0].y), &(sys[0].a), &(sys[0].z));
	printf("%d %d %d %ld\n", sys[0].x, sys[0].y, sys[0].a, sys[0].z);

	sys[1].x = 13;
	sys[1].y = 145;
	sys[1].a = 12;
	sys[1].z = 900;
	printf("memory size allocated is %ld\n", sizeof(sys[20]));
	printf("%ld %ld %ld %ld\n", &(sys[1].x), &(sys[1].y), &(sys[1].a), &(sys[1].z));
	printf("%d %d %d %ld\n", sys[1].x, sys[1].y, sys[1].a, sys[1].z);

	//Another way of Structures
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

	struct student
	{
		char *sub;
		int marks;
	};

	struct student *Virat;
	Virat = (struct student *)malloc(sizeof(struct student));
	Virat->sub = "English";
	Virat->marks = 87;
	printf("Virat scored %d marks in %s subject\n", Virat->marks, Virat->sub);
	free(Virat);
	struct student Ashwin;
	Ashwin.sub = "Maths";
	Ashwin.marks = 98;
	printf("Ashwin scored %d marks in %s subject\n", Ashwin.marks, Ashwin.sub);
	return 0;
}



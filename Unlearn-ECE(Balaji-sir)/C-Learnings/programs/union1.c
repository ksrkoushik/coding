#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	union xyz
	{
		char x;//1 byte
		short y;//2 byte
		long z;//8 byte
	};
	//In structures we have different allocations for different data types, but for unions
	// it allocates only the maximum size among the given data types, for example, here it is 8 bytes.
	// In Unions, we overwrite the memory and these unions are very rarely used.
	union xyz abc;
       	abc.x = 10;
	printf("mem allocated is %ld\n", sizeof(abc));
	abc.y = 20;
	printf("the values of x is %d and y is %d\n", abc.x, abc.y);//observe the output of this line(overwriting) happens.
	// The main difference b/w structure and union is that structure has individual space but union has a common space.
	return 0;
}

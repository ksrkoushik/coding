#include <stdio.h>

int main()
	{
		struct xyz
		{
			char x;
			short y;
			long z;
		};
		struct xyz abc;
		abc.x = 10;
		abc.y = 20;
		abc.z = 40;
		printf("%d %d% ld\n", abc.x,abc.y,abc.z);
		printf("%ld\n", sizeof(abc));
		printf("%ld %ld %ld\n", &(abc.x), &(abc.y), &(abc.z));
		return 0;
	}

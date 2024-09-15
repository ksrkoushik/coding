#include <stdio.h>

int main(int argc, char* argv[])
{
	char a[33] = "AA OAKXGXA.DR1 .N678DL039F705DEF ";
	printf("%s", a);
	printf("\n");
	for(int i=0; i<33; i++)
	{
		printf("%x",a[i]);
	}
	printf("\n");
	return 0;
}

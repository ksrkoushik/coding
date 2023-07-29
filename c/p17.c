// To use strings
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	//Defines four strings:
	char name[20];
	char total[20] = "Hello ";
	printf("what is your name: ");
	scanf("%s", &name);
	printf("-------------------------------------\n");	
	printf("%s%s\n",total,name);
	printf("Your name is %ld characters long \n", strlen(name));
	printf("-------------------------------------\n");
	return 0;
}

#include <stdio.h>
int main()
{
	int grade;
	scanf("%d", &grade);
	if(grade >= 80)
	{
		printf("Execllent Job!!!\n");
	}
	else if((grade >= 60 &grade <80))		
		printf("Not bad...\n");
	else if(grade < 60)
	{
		printf("Oh sorry, you didn't pass..\n");
	}
	return 0;
}

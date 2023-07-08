#include <stdio.h>

void Get_data(char *name, int age, int salary)
{
	printf("Name is %s\n", name);
	printf("Age is %d\n", age);
	printf("Salary is %d\n", salary);
}

int main()
{
	Get_data("Sri", 39, 70000);
	return 0;
}

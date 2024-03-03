#include <stdio.h>
#include <string.h>

struct Person 
{
	char name[30];
	int age;
	float height;
};

int main(int argc, char *argv[])
{
	struct Person person1;
	strncpy(person1.name, "Sachin", sizeof(person1.name) - 1);
	//here we are passing the null terminator
	person1.name[sizeof(person1.name) - 1] = '\0';
	person1.age = 30;
	person1.height = 5.9;
	
	printf("Name: %s\n", person1.name);
	printf("Age: %d\n", person1.age);
	printf("Height: %.2f\n", person1.height);
	return 0;
}




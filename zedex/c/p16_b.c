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
	person1.height = 5.8;
	
	printf("Name: %s\n", person1.name);
	printf("Age: %d\n", person1.age);
	printf("Height: %.2f\n", person1.height);

	struct Person person2;
	strncpy(person2.name, "Dravid", sizeof(person2.name) - 1);
	//here we are passing the null terminator
	person2.name[sizeof(person2.name) - 1] = '\0';
	person2.age = 35;
	person2.height = 5.9;

	printf("Name: %s\n", person2.name);
	printf("Age: %d\n", person2.age);
	printf("Height: %.2f\n", person2.height);
	return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Person {
  char name[50];
  int age;
  float height;
};

void printPerson(struct Person p)
{
  printf("Name:%s\n", p.name);
  printf("Age:%d\n",p.age);
  printf("Height:%.2f\n",p.height);
}

int main()
{
  struct Person person1;
  strncpy(person1.name, "Vish", 50);
  person1.name[49] = '\0';
  person1.age = 30;
  person1.height = 5.9;
  printf("Person1's information: \n");
  printPerson(person1);
  return 0;
}

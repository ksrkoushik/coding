// This is a file consisting of all the concepts covered till date

// Here we are including some predefined libraries
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>


// This function helps us understanding Sizes, Types and Arrays
void Sizes_Arrays()
{
	char *students[] = {"Sri", "Vish", "Vijay"};
	int marks[] = {57, 67, 89};
	char name[] = {'S','R', 'I'};
	printf("The size of an int: %ld\n", sizeof(int));
	printf("The size of a char: %ld\n", sizeof(char));
	printf("The size of complete students array: %ld\n", sizeof(students));
	printf("The size of each element in students array: %ld\n", sizeof(*students));
	printf("The size of each element in students array in another way: %ld\n", sizeof(students[0]));
	printf("first student name is: %s\n", students[0]);
	printf("The size of complete marks array: %ld\n", sizeof(marks));
	printf("The size of each element in marks array: %ld\n", sizeof(*marks));
	printf("The size of each element in marks array in another way: %ld\n", sizeof(marks[0]));
	printf("second student marks is: %d\n", marks[1]); 
	printf("The size of complete name array: %ld\n", sizeof(name));
	printf("The size of each element in name array: %ld\n", sizeof(*name));
	printf("The size of each element in name array in another way: %ld\n", sizeof(name[0]));
	printf("name = %s\n", name);
	students[0] = "Venky";
	printf("Now, the first student name is: %s\n", students[0]);
	printf("The new size of complete students array: %ld\n", sizeof(students));
	students[3] = "Ramu";
	printf("fourth student name is %s\n", students[3]);
	printf("The new size of complete students array: %ld\n", sizeof(students));
	printf("starting mem location of students array is: %p\n", *students);
	printf("first element name in students array is %s and its mem loc is %p\n",*students, *students);
	printf("second element name in students array is %s and its mem loc is %p\n", *(students+1), *(students+1)); 
	printf("third element in students array is %s and its mem location is %p\n",*(students+2), *(students+2));
	printf("fourth element in students array is %s and its mem location is %p\n",*(students+3),*(students+3));
	printf("fourth element in students array is %s and its mem location is %p\n", students[3], students[3]);
	printf("The New size of the complete students array is: %ld\n", sizeof(students));
}

int main(int argc, char *argv[])
{
	Sizes_Arrays();
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

void student_data(string name, int marks);

void college_data(string col_name, string br_name, void(*sample_data)(string, int));

int main(int argc, char *argv[])
{
	college_data("NITW", "ECE", student_data);
	return 0;
}

void college_data(string col_name, string br_name, void(*sample_data)(string, int))
{
	cout << "College name is: " << col_name << "\n";
	cout << "Branch name is: " << br_name << "\n";
	sample_data("Vishnu", 897);
}

void student_data(string name, int marks)
{
	cout << "Student name is: " << name << "\n";
	cout << "And he scored: " << marks << " marks out of 1000" << "\n";
}

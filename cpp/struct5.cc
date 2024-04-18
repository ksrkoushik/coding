//pointers to structures
#include <iostream>
#include <sstream>
using namespace std;

struct student_details
{
	string name;
	int marks;
}student1;

int main(int argc, char *argv[])
{
	student_details *pstudent;
	pstudent = &student1;
	cout << "Enter student name: ";
	getline(cin, pstudent->name);
	cout << "Enter student marks: ";
	cin >> pstudent->marks;
	cout << "The details of the student entered are: \n";
	cout << "Name is: " << pstudent->name;
	cout << " And Marks scored are: " << pstudent->marks << "\n";
	return 0;
}

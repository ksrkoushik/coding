//example on constructors and destructors
#include <iostream>
#include <string>
using namespace std;

class Employee
{
	string *name;
	int *age, *sal;
   public:
	Employee(string a, int b, int c);
	~Employee();
	void Emp_data(string dept)
	{
		cout << "Employee Name is: " << *name << "\n";
		cout << "Employee Age is: " << *age << "\n";
		cout << "Employee Salary is: " << *sal << "\n";
		cout << "Employee Department is: " << dept << "\n";
	}
};

Employee::Employee(string a, int b, int c)
{
	name = new string(a);
	age = new int(b);
	sal = new int(c);
	//*name = a;
	//*age = b;
	//*sal = c;
}

Employee::~Employee()
{
	delete name;
	delete age;
	delete sal;
}

int main(int argc, char *argv[])
{
	Employee emp1("Vishnu Tej", 27, 160000), emp2("Dhruv Tej", 24, 200000);
	emp1.Emp_data("ECE");
	cout << "\n";
	emp2.Emp_data("CSE");
	return 0;
}

	


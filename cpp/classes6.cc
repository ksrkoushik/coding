#include <iostream>
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int age;
    int salary;

public:
    // Constructor declaration with unnamed parameters
    Employee(string, int, int);

    // Destructor declaration
    ~Employee();

    // Member function to display employee data
    void displayEmployeeData();
};

// Constructor definition outside the class with specific parameter names
Employee::Employee(string employeeName, int employeeAge, int employeeSalary)
{
    name = employeeName;
    age = employeeAge;
    salary = employeeSalary;
}

// Destructor definition outside the class (if needed)
Employee::~Employee()
{
    // Destructor implementation (if needed)
}

// Member function definition outside the class
void Employee::displayEmployeeData()
{
    cout << "Employee Name: " << name << endl;
    cout << "Employee Age: " << age << endl;
    cout << "Employee Salary: " << salary << endl;
}

int main()
{
    // Usage of the Employee class constructor and member function
    Employee emp("John Doe", 30, 50000);
    emp.displayEmployeeData();

    return 0;
}


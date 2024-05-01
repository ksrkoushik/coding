//understanding the class overloading of constructors
#include <iostream>//library files for in-built functions
#include <string>//library for string functions
using namespace std;//to avoid writing std::

class Employee{//class declaration
   string *name;//pointer to string
   string *dept;//pointer to string
   int *sal;//pointer to int
   public://access specifier
      Employee(string, string, int);//explicit constructor
      Employee();//default constructor
      ~Employee();//destructor
      void display();//function to display the details
};

Employee::Employee(string n, string d, int s){//constructor
   name = new string;//dynamic memory allocation   
   dept = new string;
   sal = new int;
   *name = n;//assigning values to pointers
   *dept = d;
   *sal = s;
}

Employee::Employee(){//default constructor
   name = new string;//dynamic memory allocation
   dept = new string;
   sal = new int;
   *name = "Vishnu";
   *dept = "Mech";
   *sal = 40000;
}

void Employee::display(){
   cout << "Name: " << *name << "\n";
   cout << "Department: " << *dept << "\n";
   cout << "Salary: " << *sal << "\n";
}

Employee::~Employee(){//destructor
   delete name;//deleting the dynamically allocated memory
   delete dept;//deleting the dynamically allocated memory
   delete sal;//deleting the dynamically allocated memory
}

int main(int argc, char *argv[])
{
   Employee e1;
   e1.display();
   Employee e2("Ram", "CSE", 50000);
   e2.display();
   return 0;
}
  

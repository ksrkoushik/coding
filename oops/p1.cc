//class without an explicit constructor
//the compiler will generate a default constructor and a destructor
#include <iostream>
#include <string>
using namespace std;
class Employee{
public:
string name;
int age, sal;
void take_input(){
   cout << "Enter the emp-name: ";
   cin >> name;
   cout << "Enter the emp-age: ";
   cin >> age;
   cout << "Enter the emp-sal: ";
   cin >> sal;
   
}
void emp_data(){
   cout << "emp name: " << name << "\n";
   cout << "emp age: " << age << "\n";
   cout << "emp sal: " << sal << "\n";
   }

int sal_hike(int per){
   sal = sal + (sal*per)/100;
   cout << "New Salary after hike: " << sal << "\n";
   return 0;
}

};

int main(int argc, char *argv[])
{
   Employee emp1, emp2;
   // emp1 details
   emp1.take_input();
   emp1.emp_data();
   emp1.sal_hike(5);
   // emp2 details
   emp2.take_input();
   emp2.emp_data();
   emp2.sal_hike(10);
   return 0;
}


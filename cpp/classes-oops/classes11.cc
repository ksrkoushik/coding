//this
#include <iostream>
#include <string>
using namespace std; 
class CDummy { //class CDummy
 public: //access specifier
 int isitme (CDummy &param);//public member function declaration 
}; 
int CDummy::isitme (CDummy &param) //member function definition
{ 
 if (&param == this) return true; //if statement
 else return false; //else statement
}
 
int main () {//main function 
 CDummy a; //object a
 CDummy* b = &a; //pointer b
 if ( b->isitme(a) ) //if statement
 cout << "yes, &a is b" << "\n"; //print statement
 return 0; //return statement
}

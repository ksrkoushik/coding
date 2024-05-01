//understanding friend functions
#include <iostream>//header file
#include <string>//header file
using namespace std; //namespace

class CRectangle { //class
   int width, height; //data members
   public: //access specifier
      void set_values (int, int);//member function 
      int area () {return (width * height);} //member function
      friend CRectangle duplicate (CRectangle); //friend function
}; 

void CRectangle::set_values (int a, int b) { //member function definition
   width = a; //assigning value
   height = b; //assigning value
} 

CRectangle duplicate (CRectangle rectparam)//friend function definition 
{ 
   CRectangle rectres; //object
   rectres.width = rectparam.width*2;//assigning value 
   rectres.height = rectparam.height*2; //assigning value
   return (rectres); //returning value
} 

int main () { //main function
   CRectangle rect, rectb; //object
   rect.set_values (2,3); //calling member function
   rectb = duplicate (rect); //calling friend function
   cout << rectb.area() << "\n"; //printing value
   return 0; //returning value
} 


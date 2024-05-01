//Understanding of Simple Class concept by creating a class for calculator
#include <iostream>//Header file for input and output
#include <cmath>//Header file for mathematical operations
using namespace std;//Standard namespace

class Calculator{//Defining a class named Calculator
   int x,y;//Declaring two integer variables x and y
   public://Access specifier public
      Calculator(int,int);//Constructor
      void add();//Declaring a function named add
      void sub();//Declaring a function named sub
      void mul();//Declaring a function named mul
      void div();//Declaring a function named div
      void mod();//Declaring a function named mod
};

Calculator::Calculator(int a,int b){//Defining a constructor for class Calculator
   x=a;//Assigning value of a to x
   y=b;//Assigning value of b to y
}

void Calculator::add(){//Defining a function named add
   cout << "Addition: " << x + y << "\n";//Printing the addition of x and y
}

void Calculator::sub(){//Defining a function named sub
   cout << "Subtraction: " << x - y << "\n";//Printing the subtraction of x and y
}

void Calculator::mul(){//Defining a function named mul
   cout << "Multiplication: " << x * y << "\n";//Printing the multiplication of x and y
}

void Calculator::div(){//Defining a function named div
   cout << "Division: " << x / y << "\n";//Printing the division of x and y
}

void Calculator::mod(){//Defining a function named mod
   cout << "Modulus: " << x % y << "\n";//Printing the modulus of x and y
}

int main(int argc, char *argv[])//Main function
{
   Calculator Calc(34,25);//Creating an object of class Calculator
   Calc.add();//Calling the function add
   Calc.sub();//Calling the function sub
   Calc.mul();//Calling the function mul
   Calc.div();//Calling the function div
   Calc.mod();//Calling the function mod
   return 0;
}



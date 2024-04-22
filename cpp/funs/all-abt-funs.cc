#include <iostream>
#include <string>

using namespace std;

void student_data(string name, int marks, char grade, float percentage)
{
	cout << "Student name is "<< name <<" and he scored "<< marks <<" with grade "<< grade <<" and " <<percentage<<"%.\n";
}

void is_even_odd(int num)
{
	if (num%2 == 0)
	{
		cout << "Entered number is Even\n";
	}
	else
	{
		cout << "Entered number is Odd\n";
	}
}

void sum_of_1st100_nums()
{
	int i;
	int count = 0;
	for(i=0; i<=100; i++)
	{
		count+=i;
	}
	cout << "Sum of first 100 numbers is: " << count << "\n";
}

void factorial(int num)
{
	int i=1;
	int fac=1;
	for (i=1; i<=num; i++)
	{
		fac*=i;
	}
	cout << "Factorial of given number is: " << fac << "\n";
}

//Function Overloading
//In C++, two different functions can have the same name if their parameter types or number are different
//means we can give same name to morethan one function if they have either a different number of parameter 
//or different types in their parameters


//function prototype declaration
void operate(int a, int b);
void operate(double a, double b);
int main(int argc, char *argv[])
{
	student_data("Vishnu", 450, 'A', 90);
	int num;
	cout << "Please Enter the number: ";
       	cin >> num;
	is_even_odd(num);
	factorial(num);
	sum_of_1st100_nums();
	operate(100, 2);
	operate(25.50, 2.25);
	return 0;
}

void operate (int a, int b) 
{ 
 	cout << a*b << "\n";	
} 
void operate (double a, double b) 
{ 
 	cout << a/b << "\n";
}







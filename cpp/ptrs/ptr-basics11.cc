#include <iostream>
#include <string>

using namespace std;

int addition(int a , int b)
{
	return (a+b);
}

int subtraction(int a, int b)
{
	return (a-b);
}

//Passing function as an argument to another function
int operation(int x, int y, int(*functocall) (int, int))
{
	int g;
	g = (*functocall) (x,y);
	return (g);
}

int main()
{
	int m, n, s;
	// minus is a pointer to function that has two parameters of type int and 
	// is immediately assigned to the function subtraction
	int (*minus) (int, int) = subtraction;
	m = operation(7,5,addition);
	s = operation(20, m, minus);
	n = operation(8, s, subtraction);
	cout << n << "\n";
	return 0;
}

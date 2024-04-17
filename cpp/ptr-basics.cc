#include <iostream>
#include <string>

using namespace std;

// & is the reference operator and can be read as "address of"
// * is the dereference operator and can be read as "value pointed by"

int main(int argc, char *argv[])
{
	int a,b;//declaring integer variables
	int *c;//declaring pointer to integer variable
	a = 57;//assigning value
	b = a;//copying value
	c = &a;//copying mem-address of a into c
	cout << a << "\n";//printing value assigned to a
	cout << b << "\n";//storing value of a into another variable b
	cout << a << "\n";// the value is still present in a, it just copied it into b.
	cout << &a << "\n";//printing the mem-address of variable a
	cout << &b << "\n";//printing the mem-address of variable b
	cout << &c << "\n";//printing the mem-address of variable c
	cout << c << "\n";//printing the mem-address of variable a
	cout << *c << "\n";//fetching the value from mem-address of a using ptr (known as dereference operator)
	return 0;
}


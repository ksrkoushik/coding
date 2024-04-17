#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main(int argc, char *argv[])
{
	char ch = 'A';//initialize char with a single character literal
	char str[] = "Hello";//declare and initialize a character array(C-style string)
	const char *ptr = "World";//declare a pointer to a string literal(C-style string)
	string name = "John";//declare and initialize a string using string library
	char c1 = 'A';
	char c2 = c1++;//'char' arithmetic operations
	
	char *buffer = new char[100];//allocates a dynamic array of characters on heap
	const char *welcomeMsg = "Welcome to coding\n";
	strncpy(buffer, welcomeMsg, 99);
	buffer[99] = '\0';
	cout << "The single character literal\n";
	cout << ch << "\n";
	cout << "The character array (C-Style string)\n";
	cout << str << "\n";
	cout << "declaring pointer to characters\n";
	cout << ptr << "\n";
	cout << c1 << "\n";
	cout << c2 << "\n";
	cout << buffer << "\n";
	delete[] buffer;
	return 0;
}



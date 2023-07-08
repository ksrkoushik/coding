#include <iostream>
using namespace std;

void line(), message();

int main()
{
	cout << "Hello! The program starts in main().\n";
	line();
	message();
	line();
	cout << "This is the end of main().\n";
	return 0;
}

void line()
{
	cout << "-------------------------\n";
}

void message()
{
	cout << "In function message().\n";
}

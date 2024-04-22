#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	char a;
	char *b;
	char **c;
	a = 'z';
	b = &a;
	c = &b;
	cout << "mem-location of a is: " << (void *)&a << " and its value is: " << a << "\n";
	cout << "mem-location of b is: " << &b << " value of a through pointer b: " << *b << "\n";
	cout << "mem-location of b in a is: " << (void *) b << "\n";
	cout << "mem-location of c in b is: " << &c << "\n";
	cout << (void *)c << "\n";
	cout << **c << "\n";
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	char mychar = 'A';
	char *p1 = &mychar;
	cout << &p1 << "\n";
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	char *mychar;
	short *myshort;
	long *mylong;
	
	cout << "size of char: " << sizeof(char) << "\n";
	cout << "size of short: " << sizeof(short) << "\n";
	cout << "size of long: " << sizeof(long) << "\n";

	mychar = new char;
	myshort = new short;
	mylong = new long;

	cout << "address of mychar: " << static_cast<void*> (mychar) << "\n";
	cout << "address of incremented mychar: "<< static_cast<void*> (mychar+1) << "\n";
	cout << "\n";
	cout << "address of myshort:" << static_cast<void *> (myshort) << "\n";
	cout << "address of incremented myshort: " << static_cast<void *> (myshort+1) << "\n";
	cout << "\n";
	cout << "address of mylong: " << static_cast<void *> (mylong) << "\n";
	cout << "address of incremented mylong: " << static_cast<void *>(mylong+1) << "\n";

	delete mychar;
	delete myshort;
	delete mylong;
	
	return 0;
}

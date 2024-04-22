#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	const char *terry = "hello";
	cout << terry << "\n";//prints the string hello
	cout << &terry << "\n";//prints the mem-address of terry
	cout << "Printing using 1st for loop and pointer arithmetic concept\n";
	for(int i=0; i < 5; i++)
	{
		cout << *(terry + i) << "\n";// prints out each character one by one
	}
	cout << "Printing using 2nd for loop and array-index concept\n";
	for(int i=0; i < 5; i++)
	{
		cout << terry[i] << "\n";//prints out each character one by one
	}
	cout << "Printing using while loop and pointer arithmetic concept\n";
	int j = 0;
	while(j<5)
	{
		cout << *(terry + j) << "\n";
		j++;
	}
	return 0;
}

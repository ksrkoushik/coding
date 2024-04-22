//To Use Strings
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	//Defines four strings
	string prompt("What is your name: "),
	       name,
	       line( 40, '-'),
	       total = "Hello ";
	cout << prompt;
	getline(cin, name);
	total = total + name;
	cout << line <<" \n"
		<< total << "\n";
	cout << "Your name is "
		<< name.length() << " characters long! " << "\n";
	cout << line << "\n";
	return 0;
}


#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	char question[] = "Please, enter your first name: ";
	char greeting[] = "Hello, ";
	char yourname[80];
	cout << question;
	cin >> yourname;
	cout << greeting << yourname << "!"<< "\n";
	return 0;
}

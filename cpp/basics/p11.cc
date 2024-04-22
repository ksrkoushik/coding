#include <iostream>
using namespace std;
int gVar1;
int gVar2 = 2;

int main()
{
	char ch('A');
	cout << "Value of gVar1: "  <<gVar1 << "\n";
	cout << "Value of gVar2: "  <<gVar2 << "\n";
	cout << "Character in ch: "  <<ch << "\n";

	int sum, number = 3;
	sum = number + 5;
	cout << "Value of sum: " <<sum << "\n";
	return 0;
}

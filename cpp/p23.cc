#include <iostream>
using namespace std;

int main()
{
	int x;
	cout << "Enter the number: ";
	cin >> x;
	switch (x)
	{
		case 1:
			cout << "x is 100\n";
			break;
		case 2:
			cout << "x is 200\n";
			break;
		default:
			cout << "value of x is different\n";
	}
	return 0;
}

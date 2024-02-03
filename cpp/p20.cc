#include <iostream>
using namespace std;

int main()
{
	signed long n;
	cout << "Enter the Number: ";
	cin >> n;
	if (n > 0)
	{
		cout << "num is positive\n";
	}
	else if (n < 0)
	{
		cout << "num is negative\n";
	}
	else 
	{
		cout << "num is zero\n";
	}
	return 0;
}

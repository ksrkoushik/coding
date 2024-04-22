#include <iostream>
using namespace std;
void sum(double a , double b)
{
	double c = a + b;
	cout << "\nThe sum is " << c << "\n";
}
void diff(double a, double b)
{
	double c = a-b;
	cout << "\nThe diff is " << c << "\n";
}
int main()
{
	sum(123.456, 76.543);
	diff(123.456, 76.543);
	return 0;
}

//Calculating powers using the standard function pow()
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	double x = 2.5, y;
	y = pow(x, 3.0);
	cout << "2.5 raised to 3 yields: " << y << "\n";
	cout<< "5 raised to 2.5 yields: "<<pow(5, x)<< "\n";
	return 0;
}

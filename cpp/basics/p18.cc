#include <iostream>
using namespace std;
#include <cstdlib>
#include <cmath>
int main()
{
	double a,b,c,d;
	a = 4;
	b = 12.25;
	c = 0.0121;
	d = 3500;
	double y1, y2, y3, y4;
	y1 = sqrt(a);
	y2 = sqrt(b);
	y3 = sqrt(c);
	y4 = d/y3;
	y4 = d/y2;
	cout << y1 <<"\n";
	cout << y2 <<"\n";
	cout << y3 <<"\n";
	cout << y4 <<"\n";
	return 0;
}

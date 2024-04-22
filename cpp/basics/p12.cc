//Circumference and Area of a circle with raduis 2.5
#include <iostream>
using namespace std;
const double pi = 3.141593;

int main()
{
	double area, circuit, radius = 1.5;
	area = pi * radius * radius;
	circuit = 2 * pi *radius;
	cout << "\nTo Evaluate a Circle\n";
	cout << "Radius: "<<radius<<"\n"
	<< "Circumference: "<< circuit<<"\n"
	<< "Area: " <<area<<"\n";
	return 0;
}


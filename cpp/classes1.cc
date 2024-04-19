//classes example1
#include <iostream>
#include <string>
using namespace std;

class CRectangle
{
	int x, y; //by default it will be a private member
	
   public:
	void set_values(int, int);
	int area() {return (x*y);}
	int perimeter() {return (2*(x+y));}
	float cubiod(float m, float n, float o)
	{
		return m*n*o;
	}
	string name;
	int score;
};

void CRectangle::set_values(int a, int b)
{
	x = a;
	y = b;
}

int main()
{
	CRectangle rect;
	rect.set_values (30,40);
	cout << "Area: " << rect.area() << "\n";
	cout << "Perimeter: " << rect.perimeter() << "\n";
	cout << "Volume of cubiod: "<< rect.cubiod(3.5, 4.5, 5.5) << "\n";
	rect.name = "Srikanth";
	rect.score = 565;
	cout << "Name is: " << rect.name << " and score is: " << rect.score << "\n";
	return 0;
}

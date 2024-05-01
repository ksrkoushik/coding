//Understanding Overloading class constructors
#include <iostream>
#include <string>
using namespace std;

class CRectangle
{
	int width, height;
   public:
	CRectangle();
	CRectangle(int, int);
	int area ()
	{
		return width*height;
	}
};

CRectangle::CRectangle()
{
	width = 5;
	height = 5;
}

CRectangle::CRectangle(int a, int b)
{
	width = a;
	height = b;
}

int main(int argc, char *argv[])
{
	CRectangle rect(3,4);
	CRectangle rectb;
	cout << "rect area: " << rect.area() << "\n";
	cout << "rectb area: " << rectb.area() << "\n";
	return 0;
}

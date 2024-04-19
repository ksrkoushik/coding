//examples of classes
#include <iostream>
#include <string>
using namespace std;

class CRectangle
{
	int width, height;
    public:
	CRectangle (int, int);
	int area() {return (width * height);}
};

CRectangle::CRectangle (int a, int b)//constructor
{
	width = a;
	height = b;
}

int main(int argc, char *argv[])
{
	CRectangle rect (3,4);
	CRectangle rectb (5,6);
	cout << "rect area: " << rect.area() << "\n";
	cout << "rectb area: " << rectb.area() << "\n";
	return 0;
}

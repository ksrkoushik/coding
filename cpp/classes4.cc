//example on constructors and destructors
#include <iostream>
#include <string>
using namespace std;

class CRectangle
{
	int *width, *height;
    public:
	CRectangle(int, int);
	~CRectangle();
	int area() { return (*width * *height); }
};

CRectangle::CRectangle(int a, int b)
{
	width = new int;
	height = new int;
	*width = a;
	*height = b;
}

CRectangle::~CRectangle()
{
	delete width;
	delete height;
}

int main(int argc, char *argv[])
{
	CRectangle rect(3,4), rectb(5,6);
	cout << "rect area: " << rect.area() << "\n";
	cout << "rectb area: " << rectb.area() << "\n";
	return 0;
}


//Pointer to classes example
#include <iostream>
#include <string>
using namespace std;

class CRectangle
{
	int width, height;
   public:
	void set_values(int, int);
	int area(void)
	{
		return width*height;
	}
};

void CRectangle::set_values(int a, int b)
{
	width = a;
	height = b;
}

int main(int argc, char *argv[])
{
	CRectangle a, *b, *c;
	CRectangle *d = new CRectangle[2];
	b = new CRectangle;
	c = &a;
	a.set_values(1,2);
	b->set_values(3,4);
	d->set_values(5,6);
	d[1].set_values(7,8);
	cout << "a area: " << a.area() << "\n";
	cout << "*b area: " << b->area() << "\n";
	cout << "*c area: " << c->area() << "\n";
	cout << "d[0] area: " << d[0].area() << "\n";
	cout << "d[1] area: " << d[1].area() << "\n";
	delete[] d;
	delete b;
	return 0;
}



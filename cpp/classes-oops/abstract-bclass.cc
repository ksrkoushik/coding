//understanding abstract base classes
#include <iostream>
#include <string>
using namespace std;

class CPolygon
{
	protected:
	    int width, height;
	public:
	    void set_values(int a, int b)
	    {
		    width=a; height=b;
	    }
	    virtual int area(void) = 0;
};

class CRectangle:public CPolygon
{
	public:
	   int area(void)
	   {
		   return width * height;
	   }
};

class CTriangle:public CPolygon
{
	public:
	   int area(void)
	   {
		   return width*height/2;
	   }
};

int main(int argc, char *argv[])
{
	CRectangle rect;
	CTriangle trg1;
	CPolygon *p1 = &rect;
	CPolygon *p2 = &trg1;
	p1->set_values(5,7);
	p2->set_values(9,4);
	cout << p1->area() << "\n";
	cout << p2->area() << "\n";
	return 0;
}

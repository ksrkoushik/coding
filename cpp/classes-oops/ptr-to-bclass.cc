//understanding of point to base class concept
#include <iostream>
#include <string>
using namespace std;

class CPolygon
{
	protected:
	    int width,height;
	public:
	    void set_values(int a, int b)
	    {
		    width=a; height=b;
	    };
};

class CRectangle:public CPolygon
{
	public:
	    int area()
	    {
		    return width*height;
	    }
};

class CTriangle:public CPolygon
{
	public:
	   int area()
	   {
		   return width*height/2;
	   }
};

int main(int argc, char *argv[])
{
	CRectangle rect, trg1;
	CPolygon *p1 = &rect;
	CPolygon *p2 = &trg1;
	p1->set_values(4,5);
	p2->set_values(6,4);
	cout << rect.area() << "\n";
	cout << trg1.area() << "\n";
	return 0;
}

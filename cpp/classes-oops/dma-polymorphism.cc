//dynamic allocation and polymorphism
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
		    width=a;
		    height=b;
	    }
	    virtual int area(void)=0;
	    void printarea(void)
	    {
		    cout <<this->area()<< "\n";
	    }
};

class CRectangle:public CPolygon
{
	public:
	   int area(void)
	   {
		   return width*height;
	   }
};

class CTriangle:public CPolygon
{
	public:
	   int area(void)
	   {
		   return width *height/2;
	   }
};

int main(int argc, char *argv[])
{
	CPolygon *p1 = new CRectangle;
	CPolygon *p2 = new CTriangle;
	p1->set_values(8,9);
	p2->set_values(5,7);
	p1->printarea();
	p2->printarea();
	delete p1;
	delete p2;
	return 0;
}


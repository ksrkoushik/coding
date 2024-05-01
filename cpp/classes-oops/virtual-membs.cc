//understanding virtual memebers
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
		    width=a;
		    height=b;
	    }
	   virtual int area(){return 0;}
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

int main(int argc, char*argv[])
{
	CRectangle rect;
	CTriangle  trg1;
	CPolygon poly;
	CPolygon *p1=&rect;
	CPolygon *p2=&trg1;
	CPolygon *p3=&poly;
	p1->set_values(4,5);
	p2->set_values(6,7);
	p3->set_values(8,9);
	cout << p1->area()<< "\n";
	cout << p2->area()<< "\n";
	cout << p3->area()<< "\n";
	cout << rect.area()<< "\n";
	return 0;
}

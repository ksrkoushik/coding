//vectors: overloading operators example
#include <iostream>
#include <string>
using namespace std;

class CVector
{
	public:
		int x,y;//two variables
		CVector() {};//default constructor
		CVector (int,int);//parameterized constructor
		CVector operator + (CVector);//overloading the + operator
};
//The operator overloading allows instances of CVector to use the + operator
CVector::CVector(int a, int b)//implementation of parameterized constructor
{
	x = a;
	y = b;
}

CVector CVector::operator + (CVector param)
{
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}

int main(int argc, char *argv[])
{
	CVector a(3,1);
	CVector b(1,2);
	CVector c;
	//c = a.operator + (b);
	c = a + b;
	cout << c.x << ", "<< c.y << "\n";
	return 0;
}

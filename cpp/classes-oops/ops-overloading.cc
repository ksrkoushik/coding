//vectors: overloading operators example
#include <iostream>//library files for in-built functions
#include <string>//library for string functions
using namespace std;//to avoid writing std::

class CVector//class definition
{
	public://access specifier
		int x,y;//two variables
		CVector() {};//default constructor
		CVector (int,int);//parameterized constructor
		CVector operator + (CVector);//overloading the + operator
		CVector operator % (CVector);//overloading the % operator
};
//The operator overloading allows instances of CVector to use the + operator
CVector::CVector(int a, int b)//implementation of parameterized constructor
{
	x = a;//initializing data members
	y = b;//initializing data memebers
}

CVector CVector::operator + (CVector param)//operator overloading definition
{
	CVector temp;//object of class CVector
	temp.x = x + param.x;//adding x coordinates
	temp.y = y + param.y;//adding y coordinates
	return temp;//returning object
}

CVector CVector::operator % (CVector param)//operator overloading definition
{
	CVector temp;//object of class CVector
	temp.x = x % param.x;//performing operation on x coordinates
	temp.y = y % param.y;//performing operation on y coordinates
	return temp;//returning object
}

int main(int argc, char *argv[])//main function
{
	CVector a(17,19);//object of class CVector
	CVector b(3,4);//object of class CVector
	CVector c;//object of class CVector
	//c = a.operator + (b);
	c = a + b;//adding two vectors
	CVector d;//object of class CVector
	d = a % b;//performing mod operation on two vectors
	cout << c.x << ", "<< c.y << "\n";//printing coordinates
	cout << d.x << ", " << d.y << "\n";//printing coordinates
	return 0;//returning 0
}

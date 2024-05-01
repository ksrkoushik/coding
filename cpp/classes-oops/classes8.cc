//understanding default constructor
#include <iostream>
#include <string>
using namespace std;

class CExample
{
	public:
		int a,b,c;
		void multiply(int n, int m)
		{
			a=n;
			b=m;
			c=a*b;
			cout << c << "\n";
		}
};

int main(int argc, char *argv[])
{
	CExample ex;
	ex.multiply(7,8);
	return 0;
}

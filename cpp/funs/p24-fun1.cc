#include <iostream>
using namespace std;

int addition(int a, int b)
{
	int r;
	r = a + b;
	return r;
}

int main()
{
	int z;
	z = addition(15,17);
	cout << "The Result is " << z << "\n";
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	cout <<"memory space required for int: "<<sizeof(int) <<"bytes\n"
		<<"memory space required for float: "<<sizeof(float) <<"bytes\n"
		<<"memory space required for double: "<<sizeof(double) <<"bytes\n"
		<<"memory space required for long double: "<<sizeof(long double) <<"bytes\n"
		<<"memory space required for char: "<<sizeof(char) << "bytes\n";
	return 0;
}

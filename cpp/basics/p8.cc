#include <iostream>
#include <climits>
using namespace std;

int main()
{
	cout << "Range of types int and unsigned int\n";
	cout << "Type               Minimum         Maximum\n"
		<< "-----------------------------------------------\n";
cout << "int             "          << INT_MIN <<"      "<< INT_MAX <<"\n";
cout << "unsigned int          "  << " 0         "           << UINT_MAX<<"\n";
	return 0;
}

#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	string name;
	name = "Hanuman";
	cout << "Printing the memory location and values successively: " << "\n";
	int count = name.size();
	for(int i = 0; i < count; i++)
	{
		cout << "mem-location is: " << (void *) &name[i] << " and value is: " << name[i]<< "\n";
	}

	short myshort = 345;
	cout << "mem-location is: " << (void *)(&myshort) << " and its value is: " <<  myshort << "\n";
	return 0;
}

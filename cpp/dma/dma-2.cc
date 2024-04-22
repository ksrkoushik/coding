#include <iostream>
#include <string>

using namespace std;

int main(int argc, char*argv[])
{
	int *bobby;
	bobby = new int[5];
	bobby[0] = 87;
	bobby[1] = 78;
	bobby[2] = 98;
	bobby[3] = 67;
	bobby[4] = 57;

	cout << "Printing using array concept" << "\n";
	for (int i = 0; i < 5; i++)
	{
		cout << bobby[i] << "\n";
	}
	cout << "Now printing using pointer concept" << "\n";
	int j=0;
	while(j < 5)
	{
		cout << *(bobby + j) << "\n";
		j++;
	}
	delete[] bobby;
	return 0;
}

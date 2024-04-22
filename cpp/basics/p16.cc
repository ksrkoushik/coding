#include <iostream>
#include <cstdlib>

using namespace std;
int main()
{
	unsigned int seed;
	int z1, z2, z3;
	cout << "-----------Random Numbers--------\n";
	cout << "To initialize the random number generator,"
		<< "\n Please enter an integer value: ";
	cin >> seed;//reads an integer from the keyboard because "seed" is of the unsigned int type
	srand(seed);
	z1 = rand();
	z2 = rand();
	z3 = rand();

	cout << "\nThree random numbers: "
		<< z1 << " " << z2 << " " << z3 << "\n";
	return 0;
}

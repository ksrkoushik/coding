#include <iostream>
#include <string>

using namespace std;

void take_ints();

int main(int argc, char *argv[])
{
	char *bobby;
	bobby = new char[6];
	cout << "Enter a 5 letter word: ";
	cin >> bobby;
	cout << bobby << "\n";
	delete[] bobby;
	take_ints();
	return 0;
}

void take_ints()
{
	int *numbers = new int[5];
	cout << "Enter 5 integer numbers: " << "\n";
	for(int i = 0; i < 5; i++)
	{
		cout << "Number" << (i+1) << ": ";
		cin >> numbers[i];
	}
	cout << "You entered the following numbers: " << "\n";
	for(int i = 0; i < 5; i++)
	{
		cout << numbers[i] << "\n";
	}
	delete[] numbers;
}

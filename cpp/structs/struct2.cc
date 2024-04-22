#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct product
{
	string name;
	int weight;
	float price;
}apple, mango;

void fruits_data(product fruit);

int main(int argc, char *argv[])
{
	apple.name = "apple";
	apple.weight = 10;
	apple.price = 1200;
	mango.name = "mango";
	mango.weight = 15;
	mango.price = 1400;
	cout << "Details of first fruit: ";
	fruits_data(apple);
	cout << "Details of second fruit: ";
	fruits_data(mango);
	return 0;
}

void fruits_data(product fruit)
{
	cout << fruit.name << "\n";
	cout << fruit.weight << "\n";
	cout << fruit.price << "\n";
}

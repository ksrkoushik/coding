#include <iostream>
#include <string>

using namespace std;

struct abc
{
	string title;
	string author;
	union
	{
		double cost_rs;
		int total_cost;
	}price;
}book;

int main(int argc, char *argv[])
{
	abc *firstbook;
	firstbook = &book;
	cout << "Enter the name of the book: \n";
	getline(cin, firstbook->title);
	cout << "The Author of the book is: \n";
	getline(cin, firstbook->author);
	cout << "Enter the cost of the book in rupees: \n";
	cin >> firstbook->price.cost_rs;
	cout << "Enter the total cost of the book: \n";
	cin >> firstbook->price.total_cost;

	cout << "The Book details you entered are: \n";
	cout << "Book title is: " << firstbook->title << "\n";
	cout << "Book Author is: " << firstbook->author << "\n";
	cout << "Book cost is: " << firstbook->price.cost_rs << "\n";
	cout << "Book Total cost is: " << firstbook->price.total_cost << "\n";
	return 0;
}

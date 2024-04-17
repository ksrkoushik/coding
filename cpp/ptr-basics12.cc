#include <iostream>
#include <string>

using namespace std;

void data(string x, string y, void(*prof)(string), int(*calc)(int, int));
void printProfession(string profession);
int sal(int basic, int da);

int main(int argc, char *argv[])
{
	data("Hello world ", "Lovely Feeling ", printProfession, sal);
	return 0;
}
void printProfession(string profession) {
    cout << "Profession: " << profession << "\n";
}

void data(string x, string y, void(*prof) (string), int(*calc)(int, int))
{
	cout << x << y;
	prof("Engineer");
	calc(150000, 100000);
}
int sal(int basic, int da)
{
	int g = basic + da;
	cout << "Total Salary is: " << g << "\n";
	return 0;
}

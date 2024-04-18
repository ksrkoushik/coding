#include <iostream>
#include <string>
using namespace std;

enum colors_t {black, blue, green, cyan, red, purple, yellow, white};

int main(int argc, char *argv[])
{
	colors_t mycolor;
	int in_color;
	cout << "Enter the color index (0 to 2): \n";
	cin >> in_color;
	switch(in_color)
		{
		case 0:
			cout << "black day" << "\n";
			break;
		case 1:
			cout << "blue day" << "\n";
			break;
		case 2:
			cout << "green day" << "\n";
			break;
		default:
			cout << "Try your luck again!!" << "\n";
			break;
		}

	return 0;
}

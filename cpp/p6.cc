#include <iostream>
using namespace std;
void pause()
{
	cout << "BREAK";
}
int main()
{
	cout << "Dear reader\n"
		<< "have a ";
	pause();
	cout << "!\n";
	return 0;
}


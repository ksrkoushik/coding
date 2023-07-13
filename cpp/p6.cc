#include <iostream>
using namespace std;
void pause();
int main()
{
	cout << "Dear reader\n"
		<< "have a ";
	pause();
	cout << "!\n";
	return 0;
}
void pause()
{
	cout << "BREAK";
}

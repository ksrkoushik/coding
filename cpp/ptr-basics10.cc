#include <iostream>
#include <string>

using namespace std;

void increase(void *data, int psize);

int main(int argc, char *argv[])
{
	char a = 'x';
	int b = 1602;
	increase(&a, sizeof(a));
	increase(&b, sizeof(b));
	cout << a << ", " << b << "\n";
	return 0;
}

void increase(void *data, int psize)
{
	if (psize == sizeof(char))
	{
		char *pchar;
		pchar = (char *) data;
		++(*pchar);
	}
	else if(psize == sizeof(int))
	{
		int *pint;
		pint = (int *) data;
		++(*pint);
	}
}


#include <iostream>
#include <string>

using namespace std;

void arr_calc()
{
	int billy[]={16, 22, 77, 89,12091};
	int n, result=0;
	for(n=0; n<5; n++)
	{
		result+=billy[n];
	}
	cout << result << "\n";
}

int main(int argc, char *argv[])
{
	arr_calc();
	return 0;
}

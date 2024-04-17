#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int numbers[5];//declaring an array
	int *p;//declaring an integer to pointer
	
	p = numbers;//ptr p pointing at numbers array
	*p = 10;//assigning value 10 to the 1st element of array
	p++;//incrementing the ptr
	*p = 20;//assiging 20 to the incremented ptr location
	p = &numbers[2]; *p = 30;//assigning value 30 as the 3rd element of the array
	p = numbers + 3; *p = 40;//assigning value 40 as the 4th element of array
        p = numbers; *(p+4) = 50;//another way of assigning value 50 as the 5th element
	for(int n=0; n < 5; n++)
	{
		cout << numbers[n] << ", ";//this loop prints all the values present in numbers array one by one
	}
	cout << "\n";
	return 0;
}

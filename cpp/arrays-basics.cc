#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	int scores[5];
	cout << scores[0] << "\n";//If we declare an array, but not initialized with values, then it will print some garbage values

	char vowels[5] = {'a', 'e', 'i', 'o', 'u'};//here we just changed the type of array and rest remains the same
	cout << vowels[0] << "\n";//accessing the value using index

	int marks[] = {67, 89, 98};//here we are not defining the number of elements, but still it works
	cout << marks[2] << "\n";// accessing the value using the index
	cout << marks[3] << "\n";//here we are trying to access an element which is out of bound of the array, again we get a garbage value
	
	const char *names[] = {"Ram", "Hanuman", "Laxman"}; //try without specifying const and see what happens
							    //similarly try without putting [] and see understand the error
	cout << *names << "\n"; // we might get a warning abt char and string, but still it works
	cout << *(names+1) << "\n";//incrementing the mem-location using pointer and accessing the value

	string employees[] = {"Jack", "Jim", "Joe"};//string array
	cout << employees[1] << "\n";//accessing values using index
	cout << *employees << "\n";//accessing values using pointer
	cout << *(employees+1) << "\n";//accessing values using pointer

	int sal[] = {67000, 88000, 96000};
	cout << sal << "\n";//guess what we get in the output??
	cout << sal[2] << "\n";// accessing the value using index
	cout << *sal << "\n";
	
	int *emp_sal; //declaring pointer to int
	emp_sal = new int[2];//dynamically allocate memory for an array of 2 integers
	*emp_sal = 50000;//assigning values to array elements using pointer dereferencing, similar to emp_sal[0]
	*(emp_sal + 1) = 24000;//assigning values to array elements using pointer dereferencing, similar to emp_sal[1] 
	cout << *emp_sal << "\n";//accessing values using pointer
	cout << *(emp_sal+1) << "\n";//accessing values using pointer arithmetic
	delete[] emp_sal;//deallocating the dynamically allocated memory to avoid memory leaks
	return 0;
}

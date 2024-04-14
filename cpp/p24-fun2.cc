#include<iostream>
#include<string>

using namespace std;

void data()
{
	string players[] = {"Virat", "Dravid", "Sachin"};
	int runs[] = {10500, 9800, 11500};
	int i=0;
	int count = sizeof(runs)/sizeof(int);
	while(i<count)
	{
		cout << "Player name is: " << players[i] << "\n";
		cout << "Runs scored is: " << runs[i] << "\n";
		i++;
	}
}

int main(int argc, char *argv[])
{
	string names[] = {"Ram", "Shiv", "Laxman"};
	int scores[] = {67, 78, 89};
	int i;
	int count = sizeof(scores)/sizeof(int);
	for(i=0; i<count; i++)
	{
		cout<< "Name is:" << *(names+i) << "\n";
		cout << "Score is:" << *(scores+i) << "\n";
	}
	cout << "Another data using function\n";
	data();
	return 0;
}	

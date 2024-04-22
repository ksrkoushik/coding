#include <iostream>
#include <string>
using namespace std;

struct players_t
{
	string name;
	string sport;
	int num_awards;
}player1;

int main(int argc, char *argv[])
{
	players_t *pplayer;
	pplayer = &player1;
	cout << "Enter name of the player: ";
	getline(cin, (*pplayer).name);
	cout << "Enter the sport: ";
	getline(cin, (*pplayer).sport);
	cout << "Number of awards won: ";
	cin >> (*pplayer).num_awards;

	cout << "The player data you entered is: \n";
	cout << "Name: " << (*pplayer).name << "\n";
	cout << "Sport: " << (*pplayer).sport << "\n";
	cout << "Awards won: " << (*pplayer).num_awards << "\n";
	//For understanding the usage
	cout << pplayer->name << "\n";
	cout << (*pplayer).name << "\n";
	cout << player1.name << "\n";
	cout << &(player1.name) << "\n";
	cout << &(pplayer->name) << "\n";

	return 0;
}


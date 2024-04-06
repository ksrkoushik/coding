#include <iostream>
#include <string>

using namespace std;

class Player
{
	private:
		string name;
		int mats_played;
		int runs_scored;

	public:
		Player(string n, int m, int r)
		{
			name = n;
			mats_played = m;
			runs_scored = r;
		}

		void display_player_info()
		{
			cout << "Player name is: "<< name << "\n";
			cout << "Num of matches played: "<< mats_played << "\n";
			cout << "Runs scored: "<< runs_scored << "\n";
		}

		void update_matches(int mats)
		{
			mats_played = mats;
		}
		void updated_runs(int runs)
		{
			runs_scored = runs;
		}

};

int main()
{
	Player Player1("Sachin", 254, 10450);
	cout << "Player information: "<< "\n";
	Player1.display_player_info();
	cout << "Updating matches played: "<<"\n";
	Player1.update_matches(310);
	cout<< "Player Updated information: "<<"\n";
	Player1.display_player_info();
	Player1.updated_runs(11500);
	cout<< "Player Updated information: "<<"\n";
	Player1.display_player_info();
	return 0;
}




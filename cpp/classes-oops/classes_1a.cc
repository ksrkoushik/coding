//understanding of class without constructor
#include <iostream>//library files for in-built functions
#include <string>//library for string functions
using namespace std;//to avoid writing std::

class Player{//defining class Player
private://private members of class Player
      string Name;//string variable Name
      int age, score;//integer variables age and score
public://public members of class Player
      void set_fields(string, int, int);//function to set values of private members
      void display_player(){//function to display player details
         cout << "Name: " << Name << "\n";//display Name
         cout << "Age: " << age << "\n";//display age
         cout << "Score: " << score << "\n";//display score
      }
      void update_score(int);
};

void Player::set_fields(string n, int a, int s){//function to set values of private members
   Name = n;//set Name
   age = a;//set age
   score = s;//set score
}

void Player::update_score(int s){//function to update score
	score+=s;//add s to score
}

int main(int argc, char *argv[])//main function
{
   Player p1, p2;//creating objects of class Player
   //p1.set_fields("Rohit", 20, 100);//setting values of p1
   cout << "Player 1: \n";//display message
   p1.display_player();//display details of p1
   p2.set_fields("Virat", 25, 200);//setting values of p2
   cout << "Player 2: \n";//display message
   p2.display_player();//display details of p2
   p1.update_score(50);//update score of p1
   p1.display_player();//display details of p1
   p2.update_score(100);//update score of p2
   p2.display_player();//display details of p2
   return 0;
}

//Questions to investigate
//1) Why do we require set_fields mem-function outside the class??
//2) What happens if comment out line: p1.set_fields("Rohit", 20, 100)?

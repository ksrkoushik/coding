//understanding pointers to classes along with constructor overloading
#include <iostream>//library files for in-built functions
#include <string>//library for string functions
using namespace std;//to avoid writing std::

class Player{//class Player
   string name;//string variable name
   int mats_played;//integer variable mats_played
   int runs_scored;//integer variable runs_scored
   float avg;//float variable avg
   public://access specifier public
      Player();//constructor
      Player(string, int, int, float);//constructor
      void display();//function to display the details of the player
};

Player::Player(string n, int m, int r, float a){//constructor to initialize the variables
   name = n;//assigning the value of n to name
   mats_played = m;//assigning the value of m to mats_played
   runs_scored = r;//assigning the value of r to runs_scored
   avg = a;//assigning the value of a to avg
}

Player::Player() : name(""), mats_played(0), runs_scored(0), avg(0.0) {}//constructor to initialize the variables
   
void Player::display(){//function to display the details of the player
   cout << "Name: " << name << "\n";//displaying the name of the player
   cout << "Mats Played: " << mats_played << "\n";//displaying the mats played by the player
   cout << "Runs Scored: " << runs_scored << "\n";//displaying the runs scored by the player
   cout << "Average: " << avg << "\n";//displaying the average of the player
}

int main(int argc, char *argv[])
{
   Player *p1, p2("Sachin", 125, 9500, 67.5);//declaring a pointer p1 and an object p2
   Player *p3 = new Player[2]{Player("Dhoni", 100, 8000, 73.5), Player("Virat", 100, 7000, 65.5)};//declaring a pointer p3 and an array of objects for p3[0] and p3[1]
   p1 = new Player("Rohit", 100, 5000, 50.5);//declaring a pointer p1 and an object p1
   p1->display();//calling the display function of p1
   p2.display();//calling the display function of p2
   p3->display();//calling the display function of p3[0]
   p3[1].display();//calling the display function of p3[1]
   Player *p4 = new Player[2];//declaring a pointer p4 and an array of objects for p4[0] and p4[1]
   p4[0] = Player("Rahul", 100, 6000, 60.5);//assigning the values to p4[0]
   p4[1] = Player("Kohli", 100, 7000, 65.5);//assigning the values to p4[1]
   p4[0].display();//calling the display function of p4[0]
   p4[1].display();//calling the display function of p4[1]
   (*p1).display();
   (*p3).display();
   (*(p3+1)).display();
   p4->display();
   delete p1;
   delete[] p3;
   delete[] p4;
   return 0;
}
  


//understanding the class overloading of constructors
#include <iostream>//library files for in-built functions
#include <string>//library for string functions
using namespace std;//to avoid writing std::

class Player{//class declaration
   string *name;//pointer to string
   int *age, *score;//pointer to int
   public://access specifier
      Player(string, int, int);//constructor declaration
      Player();
      ~Player();//destructor
      void display();//function declaration
      void update_score(int);//function declaration
      void update_all(string, int, int);//function declaration
};

Player::Player(){
   name = new string;//dynamic memory allocation
   age = new int;//dynamic memory allocation
   score = new int;//dynamic memory allocation
}

Player::Player(string n, int a, int s){//constructor definition
   name = new string;//dynamic memory allocation
   age = new int;//dynamic memory allocation
   score = new int;//dynamic memory allocation
   *name = n;//assigning value to pointer
   *age = a;//assigning value to pointer
   *score = s;//assigning value to pointer
}

void Player::display(){//function definition
   cout << "Name: " << *name << "\n";//displaying value of pointer
   cout << "Age: " << *age << "\n";//displaying value of pointer
   cout << "Score: " << *score << "\n";//displaying value of pointer
}

void Player::update_score(int s){//function definition
   *score+=s;//updating value of pointer
}

void Player::update_all(string n, int a, int s){
   *name = n;
   *age = a;
   *score = s;
}
Player::~Player(){//destructor definition
   delete name;//deleting pointer
   delete age;//deleting pointer
   delete score;//deleting pointer
}

int main(int argc, char *argv[])//main function
{
   Player p1("Ram", 20, 100);//creating object
   Player p2("Shyam", 25, 200);//creating object
   cout << "Player 1 details:\n";//displaying message
   p1.display();//calling function
   p1.update_score(10);//calling function
   cout << "After updating the score: \n";//displaying message
   p1.display();//calling function
   cout << "Player 2 details:\n";//displaying message
   p2.display();//calling function
   p2.update_score(50);//calling function
   cout << "After updating the score: \n";//displaying message
   p2.display();//calling function
   Player p3;
   cout << "Player 3 details:\n";//displaying message
   p3.display();
   p3.update_all("Raj", 30, 300);
   cout << "After Updating p3 details: \n";
   p3.display();
   p2.update_all("Venky", 45, 125);
   cout << "After Updating p2 details: \n";
   p2.display();
   p1.update_all("Sri", 37, 435);
   cout << "After Updating p1 details: \n";
   p1.display();
   //cout << p1.name << "\n"; we cant do this because variables name, age and score are private memebers of class Player which cannot be accessed directly from outside the class.
   return 0;//returning value
}


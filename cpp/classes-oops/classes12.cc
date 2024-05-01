//understanding static members and static functions
#include <iostream>
#include <string>
using namespace std; 
class CDummy { //class CDummy
   public: //access specifier
      static int n;//static data member
      CDummy() {n++;};//constructor
      ~CDummy() {n--;};//destructor
      static void dummy_data();
}; 

int CDummy:: n =100;//static data member definition
void CDummy::dummy_data(){
   cout << "Hello world!" << "\n";
   cout << "Welcome to the world of coding" << "\n";
}
int main(int argc, char *argv[])//main function
{
   CDummy a;//object a of class CDummy (n value incremented by 1 becomes 101)
   CDummy b[5];//array of objects b of class CDummy (n value becomes 106)
   CDummy *c = new CDummy;//pointer to object c of class CDummy (n value becomes 107)
   cout << a.n << "\n";//prints 107
   delete c;//deletes object c
   cout << CDummy::n << "\n";//prints n value 106
   cout << b[0].n << "\n";//prints n value 106
   a.dummy_data();
   return 0;
}

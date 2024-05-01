//understanding of derived classes
#include <iostream>//header file
#include <string>//header file
using namespace std; //namespace

class mother{//base class
   public://access specifier
      mother(){//constructor
         cout << "mother: no parameters" << "\n";//prints
      }
      mother(int a){//constructor
         cout << "mother: int parameter" << "\n";//prints
      }
};

class daughter: public mother{//derived class
   public://access specifier
      daughter (int a){//constructor
         cout << "daughter: int parameter" << "\n";//prints
      }
};

class son: public mother{//derived class
   public://access specifier
      son(int a): mother (a){//constructor
         cout << "son: int parameter" << "\n";//prints
      }
};

int main(int argc, char *argv[])//main function
{
   daughter cynthia(0);//object of daughter
   son daniel(0);//object of son
   return 0;
}


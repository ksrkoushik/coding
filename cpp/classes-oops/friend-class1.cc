//understanding friend classes
#include <iostream>//header file
#include <string>//header file
using namespace std; //namespace

class CSquare;//class

class CRectangle{//class
   int width, height;//data members
   public://access specifier
      int area(){return width*height;}//member function
      void convert(CSquare a);//member function
};

class CSquare{//class
   private://access specifier
      int side;//data member
   public://access specifier
      void set_side (int a){//member function
         side=a;//side=a
      }
      friend class CRectangle;//friend class, CRectangle can access private members of CSquare
                              //but not vice-versa
};

void CRectangle::convert(CSquare a){//member function
   width = a.side;//width=a.side
   height = a.side;//height=a.side
}

int main()//main function
{
   CSquare sqr;//object of CSquare
   CRectangle rect;//object of CRectangle
   sqr.set_side(4);//set_side(4)
   rect.convert(sqr);//convert(sqr)
   cout << rect.area() << "\n";//print area
   return 0;
}


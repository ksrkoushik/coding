//understanding of derived classes
#include <iostream>//header file
#include <string>//header file
using namespace std; //namespace

class CPolygon{//class
      protected://protected
         int width, height;//variables
      public://public
         void set_values(int a, int b){//function
            width=a;//width
            height=b;//height
         }
};

class CRectangle: public CPolygon{//class
      public://public
         int area(){//function
            return width*height;//return
         }
};

class CTriangle: public CPolygon{//class
      public://public
         int area(){//function
            return width*height/2;//return
         }
};

int main(int argc, char *argv[])//main function
{
    CRectangle rect;//object
    CTriangle trg1;//object
    rect.set_values(4,5);//set values
    trg1.set_values(6,8);//set values
    cout << rect.area() << "\n";//print
    cout << trg1.area() << "\n";//print
    return 0;
}
 


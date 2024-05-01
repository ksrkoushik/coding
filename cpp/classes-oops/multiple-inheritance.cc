//understanding of multiple inheritance
#include <iostream>//header file
#include <string>//header file
using namespace std; //namespace

class CPolygon{//class
   protected://protected
      int width, height;//variables
   public://public
      void set_values(int a, int b){//function
         width = a;//width
         height = b;//height
      }
};

class COutput{//class
   public://public
      void output(int i);//function
};

void COutput::output(int i){
	cout << i << "\n";
}

class CRectangle: public CPolygon, public COutput{//class
   public://public
      int area(){//function
         return width * height;//return
      }
};

class CTriangle: public CPolygon, public COutput{//class
   public://public
      int area(){//function
         return width * height / 2;//return
      }
};

int main(int argc, char *argv[])//main function
{
   CRectangle rect;//object
   CTriangle trg1;//object
   rect.set_values(4,5);//function
   trg1.set_values(7,6);//function
   rect.output(rect.area());//function
   trg1.output(trg1.area());//function
   return 0;
}


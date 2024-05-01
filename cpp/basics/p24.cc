//understanding of char arrays and loops
#include <iostream>//header file
#include <string>//header file
using namespace std; //namespace

int main(int argc, char *argv[])
{
   char ch = 'B';
   char *p = &ch;
   const char m[] = {"Hello"};
   const char *n[] = {"hello", "world"};
   const char *ne[2][2][2] = {{
     {"ne111", "ne112"},
     {"ne121", "ne122"}
 },
 {
     {"ne211", "ne212"},
     {"ne221", "ne222"}
 }};
   cout << ch << p << *m << *n << "\n";
   //cout << ne[0][0][0]<< "\n";
   for (int i=0; i<2; i++)
      {
         for (int j=0; j<2; j++)
            {
               for (int k=0; k<2; k++)
                  {
                     cout << ne[i][j][k] << "\n";
                  }
            }
      }
   return 0;
}



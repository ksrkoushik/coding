
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
   char ch, *a;
   int n, *b;
   float m, *c;
   double s, *d;
   string v, *e;
   ch = 'A';
   a = &ch;
   n = 27;
   b = &n;
   m = 3.14;
   c = &m;
   s = 3.14159;
   d = &s;
   v = "Hello";
   e = &v;
   cout << ch << " " << n << " " << m << " "<< s << " " << v << "\n";      
   cout << *a << " " << *b << " " << *c << " " << *d << " " << *e << " " << "\n";
   cout << &ch << " " << &a << " " << &n << " " << &b << " " << &m << " " << &c << " " << &s << " " << &d << " " << &v << " " << &e << "\n";
   return 0;
}


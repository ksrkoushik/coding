#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int num;
    cin >> num;
    string mystring;
    string even, odd;
    for(int count = 0; count < num; ++count)
    {
        cin >> mystring;
        for (int i = 0; i < mystring.length(); ++i)
        {
            if(i%2 == 0)
            {
                even+=mystring[i];
            }
            else 
            {
                odd+=mystring[i];
            }
        }
    	cout << even << " " << odd << "\n";
	even.clear();
	odd.clear();
    }  
    return 0;
}


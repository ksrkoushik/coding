#include <bits/stdc++.h>

using namespace std;

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>
using namespace std;


int main()
{ 
    map< string, int> phonebook; int T; cin >> T; string name, findname; int number;
    for (int i; i<T; i++)
    {
        cin >> name;
        cin >> number;
        phonebook[name]=number;
    }

    while ( cin >> findname)
    {
        if (phonebook.find(findname) != phonebook.end()) 
        {
            cout << findname << "=" << phonebook[findname]<< "\n";
        } 
        else 
        {
            cout << "Not found" << "\n";
        }
    }
    return 0;

}


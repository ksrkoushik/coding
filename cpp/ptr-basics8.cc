#include <iostream>
#include <string>

using namespace std;

int main() {
    // Pointer to char
    char *mychar = new char;
    cout << "Initial address of mychar: " << static_cast<void*>(mychar) << "\n";

    // Pointer to short
    short *myshort = new short;
    cout << "Initial address of myshort: " << static_cast<void*>(myshort) << "\n";

    // Pointer to long
    long *mylong = new long;
    cout << "Initial address of mylong: " << static_cast<void*>(mylong) << "\n";

    // Increment char pointer
    mychar++;
    cout << "Address of incremented mychar: " << static_cast<void*>(mychar) << "\n";

    // Increment short pointer
    myshort++;
    cout << "Address of incremented myshort: " << static_cast<void*>(myshort) << "\n";

    // Increment long pointer
    mylong++;
    cout << "Address of incremented mylong: " << static_cast<void*>(mylong) << "\n";

    return 0;
}

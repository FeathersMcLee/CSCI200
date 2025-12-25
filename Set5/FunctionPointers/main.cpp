#include "Distance.h"
#include <iostream>

using namespace std;

// Simple function
int f() {return 1;}

// Add function
int add(int x, int y) {return x+y;}
int mult(int x, int y) {return x*y;}

int main() {
    // Create 2 Distances
    Distance d1 = Distance();
    d1.setFeet(3);
    d1.setInches(4);
    Distance d2 = Distance();
    d2.setFeet(4);
    d2.setInches(3); 

    // Compare distances with inequality operators
    if (d1 < d2) {
        cout << "d1 is smaller" << endl;
    } else {
        cout << "d2 is smaller" << endl;
    }

    //
    // Function Pointers
    //

    // Print the output of a function 
    cout << f() << endl;
    
    // Print the address of a function
    cout << (void*)f << endl;
    
    // Get the address of a function and assign to a variable    
    int (*pfMyFunc) (int, int);
    pfMyFunc = &add;

    // Call the function through the pointer explicitly and implicitly
    cout << (*pfMyFunc)(1,2) << endl;
    cout << pfMyFunc(3,4) << endl;

    // Reassign the pointer and call another function through the pointer
    pfMyFunc = &mult;
    cout << pfMyFunc(3,4) << endl;

    return 0;
}
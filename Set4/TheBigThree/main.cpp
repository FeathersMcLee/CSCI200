#include <iostream>
#include "Array.h"

using namespace std;

int main() {

    cout << "The Big Three - Destructor, Copy Assignment Operator and Copy Constructor" << endl;

    cout << "\nThe Destructor" << endl;
    Array *pArray1 = new Array( 3 );
    delete pArray1;

    cout << "\noutput stream insertion operator" << endl;
    pArray1 = new Array( 5 );
    pArray1->set(2,7);
    cout << pArray1 << endl;
    cout << *pArray1 << endl;

    cout << "\nCopy Assignment Operator" << endl;
    Array *pArray2 = new Array( 10 );
    cout << *pArray2 << endl;
    *pArray2 = *pArray1;
    cout << *pArray2 << endl;

    cout << "\nCopy Constructor" << endl;
    Array pArray3(*pArray1);
    cout << pArray3 << endl;

    return 0;
}
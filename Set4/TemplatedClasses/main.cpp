#include <iostream>
#include "Array.hpp"

using namespace std;

int main() {

    cout << "Templated Classes\n" << endl;


    cout << "\nCreate a Templated Array of ints" << endl;
    Array<int> *pArray1 = new Array<int>( 3 );
    for (int i = 0; i < 3; i++) 
        pArray1->set(i,i);
    cout << pArray1 << endl;
    cout << *pArray1 << endl;
    delete pArray1;

    cout << "\nCreate a Templated Array of strings" << endl;

    return 0;
}
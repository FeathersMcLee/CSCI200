#include <iostream>
#include "Cylinder.h"

using namespace std;

int main() {
    cout << "Object Oriented Programming\n" << endl;
    
    Cylinder can1;
    can1.radius = 1.75;
    can1.height = 4.5;
    cout << "The volume of can1 is " << can1.volume() << endl;

    Cylinder can2;
    can2.radius = 100.75;
    can2.height = 750.39;
    cout << "The volume of can2 is " << can2.volume() << endl;

    can1.radius = 2.5;
    cout << "The volume of can 1 is now " << can1.volume() << endl;

    return 0;
}


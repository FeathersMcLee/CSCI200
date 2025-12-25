#include "Dog.h"
#include "Cat.h"
#include "Animal.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    Animal* john = new Animal();
    john->setName("John");
    cout << john->getName() << " says ... " << endl;

    Dog odie;
    odie.setName("Odie");
    cout << odie.getName() << " says " << odie.bark() << endl;

    Cat garfield;
    garfield.setName("Garfield");
    cout << garfield.getName() << " says " << garfield.meow() << endl;

    delete john;

    return 0;
}
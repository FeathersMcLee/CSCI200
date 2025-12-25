#include "Dog.h"
#include "Cat.h"
#include "Animal.h"
#include <string>
#include <iostream>

using namespace std;

int main() {
    //Animal* john = new Animal();
    //john->setName("John");
    //cout << john->getName() << " says "; 
    //john->speak();

    Dog odie;
    odie.setName("Odie");
    //cout << odie.getName() << " says ";
    //odie.speak();

    Cat garfield;
    garfield.setName("Garfield");
    //cout << garfield.getName() << " says ";
    //garfield.speak();

    Cat arlene;
    arlene.setName("Arline");

    Animal* animalArray[3];
    animalArray[0] = &odie;
    animalArray[1] = &garfield;
    animalArray[2] = &arlene;

    for (int i = 0; i < 3; i++) {
        cout << animalArray[i]->getName() << " says ";
        animalArray[i]->speak();
    }

    //delete john;

    return 0;
}
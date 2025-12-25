#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat() {
    cout << "Creating a Cat" << endl;
}

Cat::~Cat(){
    cout << "Destroying a Cat" << endl;
}
        
void Cat::speak() {
    cout << "Cat:: Meow Meow!" << endl;
}

void Cat::draw() {
    cout << "Cat: Draw a cartoon cat" << endl;
}
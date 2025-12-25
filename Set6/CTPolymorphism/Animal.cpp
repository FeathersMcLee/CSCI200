#include "Animal.h"
#include <iostream> 

using namespace std;

Animal::Animal() {
    cout << "Creating an Animal" << endl;
    mName = "Animal";
    mHeight = 1;
    mWeight = 1;
}

Animal::~Animal() {
    cout << "Destroying an Animal" << endl;
}

string Animal::getName() {
    return mName;
}

void Animal::setName(const string& N) {
    mName = N;
    return;
}

void Animal::speak() {
    cout << "..." << endl;
}
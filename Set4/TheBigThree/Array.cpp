#include "Array.h"

// Parameterized Constructor
Array::Array(const int SIZE) {
    mpArr = new int[SIZE];
    mSize = SIZE;
    for (int i = 0; i < SIZE; i++)  
        mpArr[i] = 0;
}

// Copy Constructor
Array::Array(const Array& OTHER) {
    mSize = OTHER.size();
    mpArr = new int[mSize];
    for (int i =0; i < mSize; i++) {
        set(i, OTHER.get(i));
    }
}

// Destructor
Array::~Array() {
    if (mpArr != nullptr) {
        delete[] mpArr;
        mSize = 0;
    }
}

// Getter for size
int Array::size() const {
    return mSize;
}

// Resize an array
void Array::resize(const int SIZE) {
    if (mpArr != nullptr) {
        delete[] mpArr;
        mSize = 0;
    }

    mpArr = new int[SIZE];
    mSize = SIZE;
    for (int i = 0; i < SIZE; i++) 
        mpArr[i] = 0;
}

// Setter for a value in the array
void Array::set(const int POS, const int VAL) {
    mpArr[POS] = VAL;
}

// Getter for a value in the array
int Array::get(const int i) const {
    return mpArr[i];
}

// Copy Assignment Operator
Array& Array::operator=(const Array& OTHER) {
    if (this == &OTHER) {
        return *this;
    }
    this->resize(OTHER.size());
    for (int i = 0; i < OTHER.size(); i++) {
        this->set(i, OTHER.get(i));
    }
    return *this;
}

// output stream insertion operator
ostream& operator<<(ostream& os, const Array& ARR) {
    for (int i = 0; i < ARR.size(); i++) {
        os << ARR.get(i) << " ";
    }
    return os;
}
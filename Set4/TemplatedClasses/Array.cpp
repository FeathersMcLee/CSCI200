#include "Array.h"

// Parameterized Constructor
template <typename T>
Array<T>::Array(const int SIZE) {
    mpArr = new T[SIZE];
    mSize = SIZE;
}

// Copy Constructor
template <typename T>
Array<T>::Array(const Array<T>& OTHER) {
    mSize = OTHER.size();
    mpArr = new T[mSize];
    for (int i = 0; i < mSize; i++) {
        set(i, OTHER.get(i));
    }
}

// Destructor
template <typename T>
Array<T>::~Array() {
    if (mpArr != nullptr) {
        delete[] mpArr;
        mSize = 0;
    }
}

// Getter for size
template <typename T>
int Array<T>::size() const {
    return mSize;
}

// Resize an array
template <typename T>
void Array<T>::resize(const int SIZE) {
    if (mpArr != nullptr) {
        delete[] mpArr;
        mSize = 0;
    }

    mpArr = new T[SIZE];
    mSize = SIZE;
}

// Setter for a value in the array
template <typename T>
void Array<T>::set(const int POS, const T VAL) {
    mpArr[POS] = VAL;
}

// Getter for a value in the array
template <typename T>
T Array<T>::get(const int i) const {
    return mpArr[i];
}

// Copy Assignment Operator
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& OTHER) {
    if (this == &OTHER) {
        return *this;
    }
    this->resize( OTHER.size() );
    for (int i = 0; i < OTHER.size(); i++) {
        this->set(i, OTHER.get(i));
    }
    return *this;
}

// output stream insertion operator
template <typename T>
ostream& operator<<(ostream& os, const Array<T>& ARR) {
    for (int i = 0; i < ARR.size(); i++) {
        os << ARR.get(i) << " ";
    }
    return os;
}
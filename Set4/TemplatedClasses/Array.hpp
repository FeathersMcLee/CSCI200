#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
using namespace std;

template <typename T>
class Array { 
    public:
        Array(const int SIZE);
        Array(const Array<T>& OTHER);
        ~Array();
        int size() const;
        void resize(const int SIZE);
        void set(const int POS, const T VAL);
        T get(const int i) const;
        Array<T>& operator=(const Array<T>& OTHER);
    private:
        T *mpArr;
        int mSize;
};

template <typename T>
ostream& operator<<(ostream& os, const Array<T>& ARR);

/***********************************************************/
/*Implementations*/

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

#endif
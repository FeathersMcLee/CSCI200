/* CSCI 200: Lab 6C: L6C - The Abstract List
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // 
 *     // 
 *
 * This file creates the child class array that will be used to take a list of type array. It also impliments the functions to populate and manipulate the array.
 */
#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "List.hpp"
#include <iostream>

using namespace std;

template <typename T>
class Array : public List<T> {
    public:
        Array(); // default constructor - sets the size to zero
        //~Array();
        //int getSize(); // returns the size of the Array
        virtual T get(const int POS) const override; // function that returns the ith element of the Array
        virtual void set(const int POS, const T VALUE) override; // function that sets the ith element of the Array
        virtual void insert(const int POS, const T VALUE) override; // function that inserts the value before the ith element of the Array
        virtual void remove(const int POS) override; // function that removes the ith element of the Array
    private:
        T* array;    
};

// default constructor - sets the size to zero
template <typename T>
Array<T>::Array() {
    //this->size = 0;
    //cout << this->size << endl;
    this->array = nullptr; // Initialize array to nullptr
}

// function that returns the ith element of the Array
template <typename T>
T Array<T>::get(const int POS) const {
    if (POS < 0 || POS >= this->size) { // out of bounds
        return T();
    }
    return this->array[POS];
}

// function that sets the ith element of the Array
template <typename T>
void Array<T>::set(const int POS, const T VALUE) {
    if (POS < 0 || POS >= this->size) { // out of bounds
        return;
    }
    this->array[POS] = VALUE;
}

// function that inserts the value before the ith element of the Array
template <typename T>
void Array<T>::insert(const int POS, const T VALUE) {
    if (POS < 0 || POS > this->size) { // out of bounds        
        return;
    }
    T* newArray = new T[this->size + 1];
    for (int i = 0; i < POS; i++) {
        newArray[i] = this->array[i];
    }
    newArray[POS] = VALUE;
    for (int i = POS; i < this->size; i++) {
        newArray[i + 1] = this->array[i];
    }
    delete[] this->array;
    this->array = newArray;
    this->size++;
}

// function that removes the ith element of the Array
template <typename T>
void Array<T>::remove(const int POS) {
    if (POS < 0 || POS >= this->size) { // out of bounds
        return;
    }
    T* newArray = new T[this->size - 1];
    for (int i = 0; i < POS; i++) {
        newArray[i] = this->array[i];
    }
    for (int i = POS + 1; i < this->size; i++) {
        newArray[i - 1] = this->array[i];
    }
    delete[] this->array;
    this->array = newArray;
    this->size--;
}

#endif
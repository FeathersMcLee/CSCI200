/* CSCI 200: Lab 6C: L6C - The Abstract List
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // 
 *     // 
 *
 * This file creates the parrent class List that will be used to take a list of ether an array or linked list. This class assigns useful variables and impliments the getSize function.
 */
#ifndef LIST_HPP
#define LIST_HPP

template <typename T>
class List {
    public:
        List(); // default constructor - sets the size to zero
        int getSize(); // returns the size of the list
        virtual T get(const int POS) const = 0; // function that returns the ith element of the list
        virtual void set(const int POS, const T VALUE) = 0; // function that sets the ith element of the list
        virtual void insert(const int POS, const T VALUE) = 0; // function that inserts the value before the ith element of the list
        virtual void remove(const int POS) = 0; // function that removes the ith element of the list
    protected:
        int size; // the size of the list as an integer
        //T* data;
};

// default constructor - sets the size to zero
template <typename T>
List<T>::List() {
    size = 0;
}

// returns the size of the list
template <typename T>
int List<T>::getSize() {
    return size;
}

#endif
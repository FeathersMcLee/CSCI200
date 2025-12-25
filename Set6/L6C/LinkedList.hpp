/* CSCI 200: Lab 6C: L6C - The Abstract List
 *
 * Author: Isaac March
 * Resources used (Office Hours, Tutoring, Other Students, etc & in what capacity):
 *     // 
 *     // 
 *
 * This file creates the child class LinkedList that will be used to take a list of type LinkedList. It manipulates the list and reassigns the pointers in the correct order.
 */
#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "List.hpp"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList(); // default constructor - sets the size to zero
        //int getSize(); // returns the size of the list
        virtual T get(const int POS) const override; // function that returns the ith element of the list
        virtual void set(const int POS, const T VALUE) override; // function that sets the ith element of the list
        virtual void insert(const int POS, const T VALUE) override; // function that inserts the value before the ith element of the list
        virtual void remove(const int POS) override; // function that removes the ith element of the list
    private:
        struct Node {
            T data;
            Node* next;
            Node(const T& value) : data(value), next(nullptr) {}
        };
        Node* head;
};

// default constructor - sets the size to zero
template <typename T>
LinkedList<T>::LinkedList() {
    head = nullptr;
    //size = 0;
}

// function that returns the ith element of the list
template <typename T>
T LinkedList<T>::get(const int POS) const {
    if (POS < 0 || POS >= this->size) { // out of bounds
        return T();
    }
    Node* current = head;
    for (int i = 0; i < POS; i++) {
        current = current->next;
    }
    return current->data;
}

// function that sets the ith element of the list
template <typename T>
void LinkedList<T>::set(const int POS, const T VALUE) {
    if (POS < 0 || POS >= this->size) { // out of bounds
        return;
    }
    Node* current = head;
    for (int i = 0; i < POS; i++) {
        current = current->next;
    }
    current->data = VALUE;
}

// function that inserts the value before the ith element of the list
template <typename T>
void LinkedList<T>::insert(const int POS, const T VALUE) {
    if (POS < 0 || POS > this->size) { // out of bounds
        return;
    }
    Node* newNode = new Node(VALUE);
    if (POS == 0) {
        newNode->next = head; 
        head = newNode; 
    } else {
        Node* current = head;
        for (int i = 0; i < POS - 1; i++) {
            current = current->next; 
        }
        newNode->next = current->next; 
        current->next = newNode; 
    }
    this->size++;
}

// function that removes the ith element of the list
template <typename T>
void LinkedList<T>::remove(const int POS) {
    if (POS < 0 || POS >= this->size) { // out of bounds
        return;
    }
    if (POS == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
    } else {
        Node* current = head;
        for (int i = 0; i < POS - 1; i++) {
            current = current->next;
        }
        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    this->size--;
}

#endif
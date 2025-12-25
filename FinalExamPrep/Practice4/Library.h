#ifndef LIBRARY_H
#define LIBRARY_H 

#include "LinkedList.h"
#include <string>

class Library {
public:
    Library(); // Default constructor
    Library(const Library& other); // Copy constructor
    ~Library(); // Destructor
    Library& operator=(const Library& other); // Assignment operator

    Book* checkoutBook(const std::string& title);
    void returnBook(Book* book);

private:
    LinkedList<Book*>* mpCatalog; // Pointer to a LinkedList of Book pointers
};
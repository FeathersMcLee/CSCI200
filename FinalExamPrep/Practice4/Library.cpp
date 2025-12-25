#include "Library.h"
#include "LinkedList.h"
#include <iostream>
using namespace std;

// Default constructor implementation
Library::Library() {
    mpCatalog = new LinkedList<Book*>();
}

// Copy constructor implementation
Library::Library(const Library& other) {
    mpCatalog = new LinkedList<Book*>();
    for (int i = 0; i < other.mpCatalog->size(); i++) {
        Book* pBook = other.mpCatalog->at(i);
        mpCatalog->insert(i, new Book(pBook->getAuthor(), pBook->getTitle(), pBook->getPublicationYear()));
    }
}

// checkoutBook implementation
Book* Library::checkoutBook(const std::string TITLE) {
    for (int i = 0; i < mpCatalog->size(); i++) {
        if (mpCatalog->at(i)->getTitle() == TITLE) {
            Book* pBook = mpCatalog->at(i);
            mpCatalog->remove(i);
            return pBook;
        }
    }
    return nullptr;
}

// returnBook implementation
void Library::returnBook(Book* pBook) {
    mpCatalog->pushBack(pBook);
}
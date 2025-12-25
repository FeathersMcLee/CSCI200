#include "Book.h"
#include <iostream>
using namespace std;

Book::Book() {
    mAuthor = "Bjarne Stroustrup";
    mTitle = "The C++ Programing Language";
    mPublicationYear = "1986";
}

Book::Book(const std::string AUTHOR, const std::string TITLE, const int PUBLICATION_YEAR) {
    mAuthor = AUTHOR;
    mTitle = TITLE;
    mPublicationYear = PUBLICATION_YEAR;
}

// Getter methods implementation
std::string Book::getAuthor() const {
    return mAuthor;
}

std::string Book::getTitle() const {
    return mTitle;
}

int Book::getPublicationYear() const {
    return mPublicationYear;
}
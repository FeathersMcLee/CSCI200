#ifndef BOOK_H
#define BOOK_H 

#include <string>

class Book {
public:
    Book(); // Default constructor
    Book(const std::string& author, const std::string& title, const int publicationYear); // Parameterized constructor

    std::string getAuthor() const;
    std::string getTitle() const;
    int getPublicationYear() const;

private:
    std::string mAuthor;
    std::string mTitle;
    int mPublicationYear;
};

#endif


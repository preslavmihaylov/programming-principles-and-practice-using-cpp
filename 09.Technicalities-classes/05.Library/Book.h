#ifndef BOOK_H
#define BOOK_H

#include <ctime>
#include <string>

class Book
{
public:
    Book(std::string author, std::string title, std::string ISBN);

    std::string GetTitle() { return this->title; };
    std::string GetAuthor() { return this->author; };
    std::string GetISBN() { return this->ISBN; };
    tm GetCopyrightDate() { return this->copyrightDate; };

private:
    std::string title;
    std::string author;
    std::string ISBN;
    tm copyrightDate;
};

#endif // BOOK_H

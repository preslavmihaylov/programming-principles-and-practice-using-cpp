#ifndef BOOK_H
#define BOOK_H

#include <ctime>
#include <string>
#include <ostream>

class Book
{
public:
    enum Genre { fiction, nonfiction, periodical, biography, children };

    Book(std::string author, std::string title, std::string ISBN, double price);
    Book(std::string author, std::string title, std::string ISBN, double price, Genre genre);

    void CheckOut() { this->isCheckedOut = true; };

    Genre GetGenre() const { return this->genre; };
    std::string GetTitle() const { return this->title; };
    std::string GetAuthor() const { return this->author; };
    std::string GetISBN() const { return this->ISBN; };
    double GetPrice() const { return this->price; };
    bool IsCheckedOut() const { return this->isCheckedOut; };
    tm GetCopyrightDate() const { return this->copyrightDate; };

private:
    Genre genre;
    std::string title;
    std::string author;
    std::string ISBN;
    double price;
    bool isCheckedOut;
    tm copyrightDate;
};

bool operator==(const Book& bk1, const Book& bk2);
bool operator!=(const Book& bk1, const Book& bk2);
std::ostream& operator<<(std::ostream& os, const Book& bk);

#endif // BOOK_H

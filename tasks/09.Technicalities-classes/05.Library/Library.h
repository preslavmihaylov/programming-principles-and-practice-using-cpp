#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <ostream>
#include "Book.h"
#include "Patron.h"
#include "../00.Date-lib/Date.h"

struct Transaction
{
    Book book;
    Patron owner;
    Chrono::Date date;

    Transaction(Book book, Patron owner)
        : book(book), owner(owner) {};

    Transaction(Book book, Patron owner, Chrono::Date date)
        : book(book), owner(owner), date(date) {};
};

class Library
{
public:
    Library() {};

    bool AddBook(const std::string & author, const std::string & title, const std::string & ISBN, double price, Book::Genre genre);
    bool AddPatron(const std::string & username);
    bool MakeTransaction(const std::string & patronUsername, const std::string & bookISBN);

    void PrintTransactions(std::ostream & os);
    void PrintBooks(std::ostream & os);
    void PrintPatrons(std::ostream & os);

    std::vector<Patron> GetPatronsWithFees() const;
private:
    std::vector<Book> books;
    std::vector<Patron> patrons;
    std::vector<Transaction> transactions;
    Patron* FindPatron(const std::string & patronUsername);
    Book* FindBook(const std::string & bookISBN);
};

std::ostream& operator<<(std::ostream & os, const Transaction & transaction);

#endif // LIBRARY_H

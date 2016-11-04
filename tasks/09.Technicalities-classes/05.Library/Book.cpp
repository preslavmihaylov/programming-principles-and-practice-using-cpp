#include "Book.h"
#include <stdexcept>
#include <regex>
#include <iostream>

using namespace std;

bool IsDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

bool IsAlphabeticChar(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

bool IsValidISBN(const string & ISBN)
{
    int dashesCnt = 0;
    bool valueFound = false;

    for (int chIndex = 0; chIndex < ISBN.size(); ++chIndex)
    {
        // Is dash
        if (ISBN[chIndex] == '-')
        {
            if (valueFound == false)
            {
                return false;
            }

            ++dashesCnt;
            valueFound = false;
        }
        else if (dashesCnt < 3)
        {
            if (!IsDigit(ISBN[chIndex]))
            {
                return false;
            }

            valueFound = true;
        }
        else if (dashesCnt == 3)
        {
            if (!IsDigit(ISBN[chIndex]) && !IsAlphabeticChar(ISBN[chIndex]))
            {
                return false;
            }

            valueFound = true;
        }
        else
        {
            return false;
        }
    }

    if (dashesCnt != 3)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool operator==(const Book& bk1, const Book& bk2)
{
    return bk1.GetISBN() == bk2.GetISBN();
}

bool operator!=(const Book& bk1, const Book& bk2)
{
    return !(bk1 == bk2);
}

std::ostream& operator<<(std::ostream& os, const Book& bk)
{
    os << bk.GetTitle() << " - " << bk.GetISBN();
    return os;
}

Book::Book(string author, string title, string ISBN, double price)
    : Book(author, title, ISBN, price, Book::fiction)
{
}


Book::Book(std::string author, std::string title, std::string ISBN, double price, Genre genre)
{
    if (!IsValidISBN(ISBN))
    {
        throw runtime_error("Invalid ISBN");
    }

    this->author = author;
    this->title = title;
    this->ISBN = ISBN;
    time_t now = time(0);
    this->copyrightDate = *localtime(&now);
    this->price = price;
    this->genre = genre;
    this->isCheckedOut = false;
}

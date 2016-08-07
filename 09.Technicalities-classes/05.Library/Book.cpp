#include "Book.h"

using namespace std;

bool IsValidISBN(string ISBN)
{

}

Book::Book(string author, string title, string ISBN)
{
    this->author = author;
    this->title = title;
    this->ISBN = ISBN;
    time_t now = time(0);
    this->copyrightDate = *localtime(&now);
}

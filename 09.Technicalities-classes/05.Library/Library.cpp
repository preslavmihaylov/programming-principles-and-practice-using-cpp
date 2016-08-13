#include "Library.h"

using namespace std;

static int CardNumberCounter = 1;

std::ostream& operator<<(std::ostream & os, const Transaction & transaction)
{
    os << transaction.date << " --> " << transaction.owner << " --> " << transaction.book;

    return os;
}

Patron* Library::FindPatron(const string & patronUsername)
{
    for (int cnt = 0; cnt < this->patrons.size(); ++cnt)
    {
        if (this->patrons[cnt].GetUsername() == patronUsername)
        {
            return &this->patrons[cnt];
        }
    }

    return NULL;
}

Book* Library::FindBook(const string & bookISBN)
{
    int cnt;

    for (cnt = 0; cnt < this->books.size(); ++cnt)
    {
        if (this->books[cnt].GetISBN() == bookISBN)
        {
            return &this->books[cnt];
        }
    }

    return NULL;
}

bool Library::AddBook(const string & author, const string & title, const string & ISBN, double price, Book::Genre genre)
{
    if (this->FindBook(ISBN) == NULL)
    {
        Book book(author, title, ISBN, price, genre);
        this->books.push_back(book);
        return true;
    }

    return false;
}

bool Library::AddPatron(const string & username)
{
    if (this->FindPatron(username) == NULL)
    {
        Patron patron(username, CardNumberCounter++);
        this->patrons.push_back(patron);
        return true;
    }

    return false;
}

vector<Patron> Library::GetPatronsWithFees() const
{
    vector<Patron> patronsWithDebt;

    for (int cnt = 0; cnt < this->patrons.size(); ++cnt)
    {
        if (this->patrons[cnt].HasFees())
        {
            patronsWithDebt.push_back(this->patrons[cnt]);
        }
    }

    return patronsWithDebt;
}

bool Library::MakeTransaction(const string & patronUsername, const string & bookISBN)
{
    Patron * patron = this->FindPatron(patronUsername);
    Book * book = this->FindBook(bookISBN);

    if (patron == NULL || book == NULL)
    {
        return false;
    }
    else if ((*book).IsCheckedOut() == true)
    {
        return false;
    }


    time_t t = time(0);   // get time now
    struct tm * now = localtime( &t );

    this->transactions.push_back(Transaction((*book),
                                             (*patron),
                                             Chrono::Date((now->tm_year + 1900),
                                                          (Chrono::Date::Month)(now->tm_mon + 1),
                                                          now->tm_mday)
                                            ));
    (*patron).SetFee((*book).GetPrice());
    (*book).CheckOut();


    return true;
}

void Library::PrintTransactions(std::ostream & os)
{
    for (int cnt = 0; cnt < this->transactions.size(); ++cnt)
    {
        os << this->transactions[cnt] << endl;
    }
}

void Library::PrintBooks(std::ostream & os)
{
    for (int cnt = 0;cnt < this->books.size(); ++cnt)
    {
        os << this->books[cnt] << endl;
    }
}

void Library::PrintPatrons(std::ostream & os)
{
    for (int cnt = 0; cnt < this->patrons.size(); ++cnt)
    {
        os << this->patrons[cnt] << endl;
    }
}

#include <iostream>
#include "Book.h"

using namespace std;

int main()
{
    Book book("pesho", "PeshoBook", "13232");

    cout << "Title: " << book.GetTitle() << endl;
    cout << "Author: " << book.GetAuthor() << endl;
    cout << "CopyrightDate Year: " << book.GetCopyrightDate().tm_year + 1900 << endl;
    cout << "ISBN: " << book.GetISBN() << endl;

    cout << "Hello world!" << endl;
    return 0;
}

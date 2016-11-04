#include <iostream>
#include "Library.h"

using namespace std;

int main()
{
    Library lib;

    lib.AddPatron("gosho");
    lib.AddPatron("pesho");
    lib.PrintPatrons(cout);

    lib.AddBook("Pesho", "Peshobook", "123-123-12-1", 5.50, Book::fiction);
    lib.AddBook("Pesho", "Peshobook2", "123-123-12-2", 5.50, Book::fiction);
    lib.PrintBooks(cout);

    lib.MakeTransaction("gosho", "123-123-12-1");
    lib.MakeTransaction("gosho", "123-123-12-2");

    // Fails -> book already checked out
    lib.MakeTransaction("pesho", "123-123-12-2");
    lib.PrintTransactions(cout);

    vector<Patron> patronsWithFees = lib.GetPatronsWithFees();

    for (int cnt = 0; cnt < patronsWithFees.size(); ++cnt)
    {
        cout << patronsWithFees[cnt].GetUsername() << " --> " << patronsWithFees[cnt].GetLibraryFee() << endl;
    }

    /*
    Book bk1("pesho", "PeshoBook", "112-12-12-223");
    Book bk2("pesho1", "Vardar", "112-12-12-213", Book::nonfiction);

    cout << (bk1 != bk2) << endl;
    cout << bk1 << endl;

    if (bk2.GetGenre() == Book::nonfiction)
    {
        cout << "Non fiction" << endl;
    }
    */
    return 0;
}

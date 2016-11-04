#ifndef PATRON_H
#define PATRON_H

#include <string>
#include <ostream>

class Patron
{
public:
    Patron(std::string username, int cardNumber);
    void SetFee(double fee);

    std::string GetUsername() const { return this->username; }
    int GetCardNumber() const { return this->cardNumber; }
    double GetLibraryFee() const { return this->libraryFee; }
    bool HasFees() const { return this->libraryFee > 0; }
private:
    std::string username;
    int cardNumber;
    double libraryFee;
};

std::ostream& operator<<(std::ostream & os, const Patron & patron);

#endif // PATRON_H

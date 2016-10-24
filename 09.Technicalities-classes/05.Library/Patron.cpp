#include "Patron.h"

std::ostream& operator<<(std::ostream & os, const Patron & patron)
{
    os << patron.GetUsername() << " - " << patron.GetCardNumber();

    return os;
}

Patron::Patron(std::string username, int cardNumber)
    : username(username), cardNumber(cardNumber), libraryFee(0) {};

void Patron::SetFee(double fee)
{
    this->libraryFee += fee;
}

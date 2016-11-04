#ifndef MONEY_H
#define MONEY_H

#include <ostream>

class Money
{
public:
    enum Currency
    {
        USD,
        GBP,
        EURO,
        BGN,
        CurrenciesCount
    };

    Money()
        : cents(0) {};
    Money(double value);
    Money(long cents);
    Money(double value, Money::Currency currency);

    long GetCents() const;
    long GetDollars() const;
    Currency GetCurrency() const;

    void SetCurrency(Currency currency);

    friend Money operator+(const Money & first, const Money & second);
    friend Money operator-(const Money & first, const Money & second);
private:
    Currency outputCurrency;
    long cents;
};

std::ostream& operator<<(std::ostream& os, const Money& money);

#endif // MONEY_H

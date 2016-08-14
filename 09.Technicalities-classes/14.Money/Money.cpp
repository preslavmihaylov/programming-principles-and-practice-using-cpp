#include "Money.h"
#include <stdexcept>
#include <string>

using namespace std;

#define DEFAULT_CURRENCY (Currency::USD)

static double CURRENCY_CONV_TABLE[Money::Currency::CurrenciesCount] =
{
    1, // USD
    0.77, // GBP
    0.90, // EURO
    1.75 // BGN
};

static string CURRENCY_NAMES[Money::Currency::CurrenciesCount] =
{
    "USD",
    "GBP",
    "EURO",
    "BGN"
};

ostream& operator<<(ostream& os, const Money& money)
{
    os << money.GetDollars() << "." << money.GetCents() << " " << CURRENCY_NAMES[money.GetCurrency()];
    return os;
}

Money operator+(const Money & first, const Money & second)
{
    Money result(first.cents + second.cents);
    result.SetCurrency(first.outputCurrency);

    return result;
}

Money operator-(const Money & first, const Money & second)
{
    Money result(first.cents - second.cents);
    result.SetCurrency(first.outputCurrency);

    return result;
}

Money::Money(double value)
{
    if (value < 0)
    {
        throw runtime_error("Value cannot be negative");
    }

    long totalCents = (long)(value * 1000);
    long roundUp = 0;

    if (totalCents % 10 >= 5)
    {
        ++roundUp;
    }

    totalCents /= 10;

    this->SetCurrency(DEFAULT_CURRENCY);
    this->cents = totalCents + roundUp;
}

Money::Money(long cents)
{
    if (cents < 0)
    {
        throw runtime_error("Value cannot be negative");
    }

    this->SetCurrency(DEFAULT_CURRENCY);
    this->cents = cents;
}

Money::Money(double value, Money::Currency currency)
    : Money(value)
{
    this->SetCurrency(currency);
    this->cents /= CURRENCY_CONV_TABLE[currency];
}

long Money::GetCents() const
{
    return ((long)(this->cents * CURRENCY_CONV_TABLE[this->outputCurrency]) % 100);
}

long Money::GetDollars() const
{
    return ((long)(this->cents * CURRENCY_CONV_TABLE[this->outputCurrency]) / 100);
}

Money::Currency Money::GetCurrency() const
{
    return this->outputCurrency;
}

void Money::SetCurrency(Currency currency)
{
    if (currency >= Money::CurrenciesCount)
    {
        throw runtime_error("Invalid currency");
    }

    this->outputCurrency = currency;
}

#include "Rational.h"

#define FRACTIONAL_BASE (1000)

int greatestCommonDivisor(int first, int second)
{
    if (second == 0)
    {
        return first;
    }

    return greatestCommonDivisor(second, first % second);
}

std::ostream& operator<<(std::ostream& os, const Rational & rational)
{
    os << rational.numerator << "/" << rational.denominator;
    return os;
}

Rational operator+(const Rational& num1, const Rational& num2)
{
    Rational result;

    result.numerator = (num1.numerator * num2.denominator) + (num2.numerator * num1.denominator);
    result.denominator = num1.denominator * num2.denominator;
    result.SimplifyRational();

    return result;
}

Rational operator-(const Rational& num1, const Rational& num2)
{
    Rational result;

    result.numerator = (num1.numerator * num2.denominator) - (num2.numerator * num1.denominator);
    result.denominator = num1.denominator * num2.denominator;
    result.SimplifyRational();

    return result;
}

Rational operator*(const Rational& num1, const Rational& num2)
{
    Rational result;

    result.numerator = num1.numerator * num2.numerator;
    result.denominator = num1.denominator * num2.denominator;
    result.SimplifyRational();

    return result;
}

Rational operator/(const Rational& num1, const Rational& num2)
{
    Rational result;

    result = num1 * Rational(num2.denominator, num2.numerator);
    result.SimplifyRational();

    return result;
}

Rational::Rational(double number)
{
    int decimalPart = (int) number;
    double fractionalPart = number - (int)number;

    this->numerator = (int)(fractionalPart * FRACTIONAL_BASE);
    this->numerator += decimalPart * FRACTIONAL_BASE;
    this->denominator = FRACTIONAL_BASE;

    this->SimplifyRational();
}

Rational::Rational(int numerator, int denominator)
    : numerator(numerator), denominator(denominator)
{
    this->SimplifyRational();
}

double Rational::GetDoubleValue()
{
    return (this->numerator / this->denominator);
}

void Rational::SimplifyRational()
{
    int gcd = greatestCommonDivisor(this->numerator, this->denominator);

    this->numerator /= gcd;
    this->denominator /= gcd;
}

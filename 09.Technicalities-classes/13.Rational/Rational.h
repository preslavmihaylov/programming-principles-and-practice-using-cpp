#ifndef RATIONAL_H
#define RATIONAL_H

#include <ostream>

class Rational
{
public:
    Rational(double number);
    Rational(int numerator, int denominator);
    Rational()
        : numerator(0), denominator(1) {};

    double GetDoubleValue();

    friend Rational operator+(const Rational& num1, const Rational& num2);
    friend Rational operator-(const Rational& num1, const Rational& num2);
    friend Rational operator*(const Rational& num1, const Rational& num2);
    friend Rational operator/(const Rational& num1, const Rational& num2);
    friend std::ostream& operator<<(std::ostream& os, const Rational & rational);
private:
    int numerator;
    int denominator;
    void SimplifyRational();
};

#endif // RATIONAL_H

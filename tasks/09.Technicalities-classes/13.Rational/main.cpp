#include <iostream>
#include "Rational.h"

using namespace std;

int main()
{
    Rational number(12.5);
    Rational number1(3.333);
    cout << 12.5 << " = " << number << endl;
    cout << 3.333 << " = " << number1 << endl;

    Rational first(2, 3);
    Rational second(4, 9);
    Rational third(5, 6);
    Rational fourth(1, 2);

    cout << first << " + " << first << " = " << (first + first) << endl;
    cout << first << " - " << first << " = " << (first - first) << endl;
    cout << second << " + " << third << " = " << (second + third) << endl;
    cout << third << " * " << fourth << " = " << (third * fourth) << endl;
    return 0;
}

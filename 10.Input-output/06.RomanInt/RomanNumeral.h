#ifndef ROMAN_NUMERAL_H
#define ROMAN_NUMERAL_H

#include <string>
#include <istream>

class RomanNumeral
{
public:
    RomanNumeral()
        : value(0), stringValue("") {};
    RomanNumeral(std::string input);
    int AsInt();

    friend std::istream &operator>>(std::istream& is, RomanNumeral& romanNumeral);
    friend std::ostream &operator<<(std::ostream& os, const RomanNumeral& romanNumeral);
private:
    int value;
    std::string stringValue;
    void ProcessInputString(std::string input);
};

extern bool IsValidRomanDigit(char digit);

#endif // ROMAN_NUMERAL_H

#include "../headers/RomanNumeral.h"

#include <unordered_map>
#include <climits>


using namespace std;

#define INVALID_VALUE (-1)

int GetNextNumeralValue(char romanNumeral);
bool IsValidRomanDigit(char digit);
int GetNextDigitValue(const string& input, int& inputIndex, char& highestNumeral);
int ParseRomanNumeral(string input);

static const unordered_map<char, int> DigitValues =
{
    { 'I', 1},
    { 'V', 5},
    { 'X', 10},
    { 'L', 50},
    { 'C', 100},
    { 'D', 500},
    { 'M', 1000}
};

int GetNextNumeralValue(char romanNumeral)
{
    switch (romanNumeral)
    {
        case 'I':
            return DigitValues.at('V');
        case 'V':
            return DigitValues.at('X');
        case 'X':
            return DigitValues.at('L');
        case 'L':
            return DigitValues.at('C');
        case 'C':
            return DigitValues.at('D');
        case 'D':
            return DigitValues.at('M');
        case 'M':
            return INT_MAX;
        default:
            return INVALID_VALUE;
    }
}

bool IsValidRomanDigit(char digit)
{
    switch (digit)
    {
        case 'I':
        case 'V':
        case 'X':
        case 'L':
        case 'C':
        case 'D':
        case 'M':
            return true;
        default:
            return false;
    }
}

int GetNextDigitValue(const string& input, int& inputIndex, char& highestNumeral)
{
    char digit;

    if (inputIndex < input.size())
    {
        digit = toupper(input[inputIndex]);

        if (IsValidRomanDigit(digit) && IsValidRomanDigit(highestNumeral))
        {
            // Check for subtractive numeral
            if (inputIndex + 1 < input.size())
            {
                char nextDigit = toupper(input[inputIndex + 1]);

                if (((digit == 'I') && (nextDigit == 'V' || nextDigit == 'X')) ||
                    ((digit == 'X') && (nextDigit == 'L' || nextDigit == 'C')) ||
                    ((digit == 'C') && (nextDigit == 'D' || nextDigit == 'M'))
                   )
                {
                    inputIndex += 2;
                    if (DigitValues.at(highestNumeral) < DigitValues.at(nextDigit))
                    {
                        highestNumeral = nextDigit;
                    }

                    return (DigitValues.at(nextDigit) - DigitValues.at(digit));
                }
            }

            ++inputIndex;
            if (DigitValues.at(highestNumeral) < DigitValues.at(digit))
            {
                highestNumeral = digit;
            }

            return DigitValues.at(digit);
        }
    }

    return INVALID_VALUE;
}

// reference: https://projecteuler.net/about=roman_numerals
int ParseRomanNumeral(string input)
{
    int inputIndex = 0;
    int lastValue = INT_MAX;
    int currentValue;
    int totalValue = 0;
    char highestNumeral = 'I';
    int cntD = 0;
    int cntL = 0;
    int cntV = 0;

    while (inputIndex < input.size())
    {
        currentValue = GetNextDigitValue(input, inputIndex, highestNumeral);
        if (currentValue == INVALID_VALUE)
        {
            return INVALID_VALUE; // Invalid digit
        }

        // V or IV
        if ((currentValue == DigitValues.at('V')) ||
            (currentValue == (DigitValues.at('V') - DigitValues.at('I'))))
        {
            ++cntV;
        }

        // L or XL
        if ((currentValue == DigitValues.at('L')) ||
            (currentValue == (DigitValues.at('L') - DigitValues.at('X'))))
        {
            ++cntL;
        }

        // D or CD
        if ((currentValue == DigitValues.at('D')) ||
            (currentValue == (DigitValues.at('D') - DigitValues.at('C'))))
        {
            ++cntD;
        }

        if (currentValue > lastValue)
        {
            return INVALID_VALUE; // Rule 1
        }

        lastValue = currentValue;
        totalValue += currentValue;

        if (GetNextNumeralValue(highestNumeral) <= totalValue)
        {
            return INVALID_VALUE; // Rule 2
        }

        if ((cntD > 1) ||
            (cntL > 1) ||
            (cntV > 1))
        {
            return INVALID_VALUE; // Rule 3
        }
    }

    return totalValue;
}

void RomanNumeral::ProcessInputString(string input)
{
    int value = ParseRomanNumeral(input);
    if (value == INVALID_VALUE)
    {
        throw runtime_error("Invalid roman numeral");
    }

    this->value = value;
    this->stringValue = input;
}


std::istream &operator>>(std::istream& is, RomanNumeral& romanNumeral)
{
    string input;
    char digit;

    is >> digit;
    while (is.good() && IsValidRomanDigit(digit))
    {
        input += digit;
        is >> digit;
    }

    if (is.good())
    {
        is.putback(digit);
    }

    romanNumeral.ProcessInputString(input);

    return is;
}

std::ostream &operator<<(std::ostream& os, const RomanNumeral& romanNumeral)
{
    os << romanNumeral.stringValue;
    return os;
}


RomanNumeral::RomanNumeral(string input)
{
    this->ProcessInputString(input);
}

int RomanNumeral::AsInt()
{
    return this->value;
}

#include <map>
#include <cassert>
#include <iostream>
#include <fstream>

#include "../headers/Token.h"
#include "../headers/Utilities.h"

#define UNDERSCORE '_'

ifstream inputStream;
ofstream outputStream;

map<string, eTokenType> keywords =
{
    {"let", eTokenTypeLet},
    {"sqrt", eTokenTypeSqrt},
    {"pow", eTokenTypePow},
    {"help", eTokenTypeHelp},
    {"quit", eTokenTypeQuit},
    {"exit", eTokenTypeExit},
    {"const", eTokenTypeConst},
    {"from", eTokenTypeInput},
    {"to", eTokenTypeOutput}
};

void SetOutputStream(string output)
{
    outputStream.close();
    outputStream.open(output);
}

ostream& GetOutputStream()
{
    if (outputStream.is_open() && !outputStream.eof() && !outputStream.fail() && !outputStream.bad())
    {
        return outputStream;
    }
    else
    {
        return cout;
    }
}

void SetInputStream(string input)
{
    inputStream.close();
    inputStream.open(input);
}

istream& GetInputStream()
{
    if (inputStream.is_open() && !inputStream.eof() && !inputStream.fail() && !inputStream.bad())
    {
        return inputStream;
    }
    else
    {
        return cin;
    }
}

eTokenType get_expected_closing_paran(eTokenType openingParan)
{
    eTokenType closingParan;

    if (openingParan == eTokenTypeLeftParan)
    {
        closingParan = eTokenTypeRightParan;
    }
    else if (openingParan == eTokenTypeLeftCurlyParan)
    {
        closingParan = eTokenTypeRightCurlyParan;
    }
    else
    {
        // Unreachable condition. Left for completeness
        assert(false);
    }

    return closingParan;
}

bool has_decimal_point(double val)
{
    return (val - (int)val > 0.00);
}

double factorial(int val)
{
    if (val == 1)
    {
        return 1;
    }

    return val * factorial(val - 1);
}

bool is_operator(char ch)
{
    switch (ch)
    {
        case eTokenTypePlus:
        case eTokenTypeMinus:
        case eTokenTypeMultiply:
        case eTokenTypeDivide:
        case eTokenTypeModulo:
        case eTokenTypeFactorial:
        case eTokenTypeLeftCurlyParan:
        case eTokenTypeRightCurlyParan:
        case eTokenTypeLeftParan:
        case eTokenTypeRightParan:
        case eTokenTypeSemicolon:
        case eTokenTypeComma:
        case eTokenTypeEqual:
            return true;
        default:
            return false;
    }
}

bool is_digit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

bool is_keyword(string id)
{
    return keywords.find(id) != keywords.end();
}

bool is_underscore(char ch)
{
    return ch == UNDERSCORE;
}

eTokenType get_keyword_id(string id)
{
    if (!is_keyword(id))
    {
        assert(false);
    }

    return keywords[id];
}

void print_help()
{
    GetOutputStream() << "Presso Calculator v0.01" << endl;
    GetOutputStream() << "Supported features:" << endl;
    GetOutputStream() << "Arithmetic expressions (Ex: 5 + 10 / 2)" << endl;
    GetOutputStream() << "Multiple expressions per line (Ex: 1+2; 2+3;)" << endl;
    GetOutputStream() << "Initialization of variables (Ex: let a = 10)" << endl;
    GetOutputStream() << "Modification of variables (Ex: a = 20)" << endl;
    GetOutputStream() << "Functions: sqrt, pow" << endl;
    GetOutputStream() << "To exit, type exit or quit" << endl;
}

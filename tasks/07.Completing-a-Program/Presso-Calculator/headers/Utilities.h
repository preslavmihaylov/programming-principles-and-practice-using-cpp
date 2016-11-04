#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>

using namespace std;

enum eTokenType
{
    eTokenTypePlus = '+',
    eTokenTypeMinus = '-',
    eTokenTypeMultiply = '*',
    eTokenTypeDivide = '/',
    eTokenTypeModulo = '%',
    eTokenTypeFactorial = '!',
    eTokenTypeLeftParan = '(',
    eTokenTypeRightParan = ')',
    eTokenTypeLeftCurlyParan = '{',
    eTokenTypeRightCurlyParan = '}',
    eTokenTypeComma = ',',
    eTokenTypeNumber = '0',
    eTokenTypeSemicolon = ';',
    eTokenTypeInvalid = '2',
    eTokenTypeLet = 'l',
    eTokenTypeConst = 'c',
    eTokenTypeSqrt = 's',
    eTokenTypePow = 'p',
    eTokenTypeVariable = 'v',
    eTokenTypeHelp = 'h',
    eTokenTypeEqual = '=',
    eTokenTypeInput = 'i',
    eTokenTypeOutput = 'o',
    eTokenTypeString = 'S',
    eTokenTypeDoubleQuotationMark = '"',
    eTokenTypeQuit = 'q',
    eTokenTypeExit = 'x',
    eTokenTypeNull = '\0',
    eTokenTypesCount
};

void SetOutputStream(string output);
ostream& GetOutputStream();
void SetInputStream(string input);
istream& GetInputStream();

eTokenType get_expected_closing_paran(eTokenType openingParan);
bool has_decimal_point(double val);
double factorial(int val);
bool is_operator(char ch);
bool is_digit(char ch);
bool is_underscore(char ch);
bool is_keyword(string id);
eTokenType get_keyword_id(string id);
void print_help();

#endif // UTILITIES_H

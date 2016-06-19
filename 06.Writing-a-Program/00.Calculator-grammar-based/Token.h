#ifndef TOKEN_H
#define TOKEN_H

enum eTokenType
{
    eTokenTypePlus = '+',
    eTokenTypeMinus = '-',
    eTokenTypeMultiply = '*',
    eTokenTypeDivide = '/',
    eTokenTypeLeftParan = '(',
    eTokenTypeRightParan = ')',
    eTokenTypeNumber = '0',
    eTokenTypeNull = '\0',
    eTokenTypesCount
};

class Token
{
public:
    char kind;
    double value;
    Token(char ch)
        : kind(ch), value(0) {};
    Token(char ch, double val)
        : kind(ch), value(val) {};
    Token()
        : kind(0), value(0) {};
};

#endif // TOKEN_H

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

using namespace std;

enum eTokenType
{
    eTokenTypeAnd = '&',
    eTokenTypeOr = '|',
    eTokenTypeXor = '^',
    eTokenTypeNegation = '!',
    eTokenTypeComplement = '~',
    eTokenTypeLeftParan = '(',
    eTokenTypeRightParan = ')',
    eTokenTypeVariable = 'v',
    eTokenTypeNull = 'n',
    eTokenTypesCount
};

class Token
{
public:
    char kind;
    bool value;
    Token(char ch)
        : kind(ch), value(false) {};
    Token(char ch, bool val)
        : kind(ch), value(val) {};
    Token()
        : kind(0), value(false) {};
};

#endif // TOKEN_H

#ifndef TOKEN_H
#define TOKEN_H

#include <string>

#include "Utilities.h"

using namespace std;

class Token
{
public:
    eTokenType kind;
    double value;
    string id;
    Token(eTokenType kind)
        : kind(kind), value(0) {};
    Token(eTokenType kind, double val)
        : kind(kind), value(val) {};
    Token(eTokenType kind, string id, double val)
        : kind(kind), value(val), id(id) {};
    Token()
        : kind((eTokenType)0), value(0) {};
};

#endif // TOKEN_H

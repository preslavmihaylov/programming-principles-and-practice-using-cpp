#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

#include "Token.h"
#include <sstream>

using namespace std;

class Token_stream
{
public:
    Token_stream();
    ~Token_stream();
    Token get();
    void putback(Token token);
    bool eof();
private:
    bool full;
    istringstream * input_str;
    Token buffer;
};


#endif // TOKEN_STREAM_H

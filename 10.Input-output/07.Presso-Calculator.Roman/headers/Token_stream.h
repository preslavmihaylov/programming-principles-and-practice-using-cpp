#ifndef TOKEN_STREAM_H
#define TOKEN_STREAM_H

#include "Token.h"
#include "Utilities.h"

#include <stack>

using namespace std;

class Token_stream
{
public:
    Token_stream(istream& inputSource);
    ~Token_stream();
    Token get();
    void putback(Token token);
    bool eof();
private:
    istringstream * input_str;
    stack<Token> buffer;
    string get_symbolic_value();
    string get_string_value();
    bool is_buffer_full();
};


#endif // TOKEN_STREAM_H

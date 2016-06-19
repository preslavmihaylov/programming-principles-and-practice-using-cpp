#include "Token_stream.h"
#include <iostream>

bool is_operator(char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
            return true;
        default:
            return false;
    }
}

bool is_digit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

Token_stream::Token_stream()
    : full(0), buffer(eTokenTypeNull)
{
    string line;
    getline(cin, line);
    this->input_str = new istringstream(line);
}

Token_stream::~Token_stream()
{
    delete this->input_str;
}

bool Token_stream::eof()
{
    return this->input_str->eof();
}

Token Token_stream::get()
{
    char curr_ch;
    double value;
    Token token;

    if (this->full == true)
    {
        this->full = false;
        return this->buffer;
    }

    *this->input_str >> curr_ch;

    if (this->input_str->eof())
    {
        token = Token(eTokenTypeNull);
        return token;
    }

    if (is_operator(curr_ch))
    {
        token = Token(curr_ch);
    }
    else if (is_digit(curr_ch))
    {
        this->input_str->putback(curr_ch);
        *this->input_str >> value;
        token = Token(eTokenTypeNumber, value);
    }
    else
    {
        token = Token(eTokenTypeNull);
    }

    return token;
}

void Token_stream::putback(Token token)
{
    this->full = true;
    this->buffer = token;
}

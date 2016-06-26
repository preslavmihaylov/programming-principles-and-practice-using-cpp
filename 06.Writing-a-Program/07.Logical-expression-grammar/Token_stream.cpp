#include "Token_stream.h"
#include <iostream>
#include <stdexcept>

bool is_operator(char ch)
{
    switch (ch)
    {
        case eTokenTypeAnd:
        case eTokenTypeOr:
        case eTokenTypeXor:
        case eTokenTypeNegation:
        case eTokenTypeComplement:
        case eTokenTypeLeftParan:
        case eTokenTypeRightParan:
            return true;
        default:
            return false;
    }
}

bool is_letter(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

bool get_bool_value(string literal)
{
    if (literal == "true")
    {
        return true;
    }
    else if (literal == "false")
    {
        return false;
    }
    else
    {
        throw runtime_error("Unrecognized literal " + literal);
    }

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

void Token_stream::ignore_whitespace()
{
    char curr_ch;
    *this->input_str >> curr_ch;

    while ((curr_ch == ' ' ||
           curr_ch == '\t' ||
           curr_ch == '\n') &&
           !this->input_str->eof())
    {
        *this->input_str >> curr_ch;
    }

    if (!this->input_str->eof())
    {
        this->input_str->putback(curr_ch);
    }
}

Token Token_stream::get()
{
    char curr_ch;
    string value;
    Token token;

    if (this->full == true)
    {
        this->full = false;
        return this->buffer;
    }

    if (this->input_str->eof())
    {
        token = Token(eTokenTypeNull);
        return token;
    }

    this->ignore_whitespace();

    *this->input_str >> curr_ch;

    if (is_operator(curr_ch) && !this->input_str->eof())
    {
        token = Token(curr_ch);
    }
    else if (is_letter(curr_ch) && !this->input_str->eof())
    {
        while (!this->input_str->eof() && is_letter(curr_ch))
        {
            value += curr_ch;
            *this->input_str >> curr_ch;
        }

        bool bool_value = get_bool_value(value);

        if (!this->input_str->eof())
        {
            this->input_str->putback(curr_ch);
        }

        token = Token(eTokenTypeVariable, bool_value);
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

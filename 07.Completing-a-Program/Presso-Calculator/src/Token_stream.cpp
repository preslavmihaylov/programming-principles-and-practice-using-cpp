#include <stack>
#include <iostream>
#include <sstream>

#include "../headers/Token_stream.h"

Token_stream::Token_stream()
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

    if (this->is_buffer_full())
    {
        token = this->buffer.top();
        this->buffer.pop();
        return token;
    }

    *this->input_str >> curr_ch;

    if (this->input_str->eof())
    {
        token = Token(eTokenTypeNull);
        return token;
    }

    if (is_operator(curr_ch))
    {
        token = Token((eTokenType)curr_ch);
    }
    else if (is_digit(curr_ch))
    {
        this->input_str->putback(curr_ch);
        *this->input_str >> value;
        token = Token(eTokenTypeNumber, value);
    }
    else if (isalpha(curr_ch) || is_underscore(curr_ch))
    {
        this->input_str->putback(curr_ch);
        string id = this->get_symbolic_value();

        if (is_keyword(id))
        {
            token = Token(get_keyword_id(id), id, 0);
        }
        else
        {
            token = Token(eTokenTypeVariable, id, 0);
        }
    }
    else
    {
        token = Token(eTokenTypeInvalid);
    }

    return token;
}

void Token_stream::putback(Token token)
{
    this->buffer.push(token);
}

/* PRIVATE METHODS */
bool Token_stream::is_buffer_full()
{
    return this->buffer.size() > 0;
}

string Token_stream::get_symbolic_value()
{
    string value;
    char curr_ch;
    *this->input_str >> curr_ch;

    // the variable cannot begin with a digit due to the check in the get() function
    while (!this->input_str->eof() && (isalpha(curr_ch) || is_digit(curr_ch) || is_underscore(curr_ch)))
    {
        value += curr_ch;
        this->input_str->get(curr_ch);
    }

    if (!this->input_str->eof())
    {
        this->input_str->putback(curr_ch);
    }

    return value;
}


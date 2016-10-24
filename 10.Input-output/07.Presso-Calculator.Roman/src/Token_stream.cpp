#include <stack>
#include <iostream>
#include <sstream>
#include <stdexcept>

#include "../headers/Token_stream.h"
#include "../headers/RomanNumeral.h"

Token_stream::Token_stream(istream& inputSource)
{
    string line;
    if (!inputSource.eof())
    {
        getline(inputSource, line);
    }
    else if (inputSource.fail())
    {
        throw runtime_error("Something unexpected happened with the input");
    }
    else if (inputSource.bad())
    {
        throw runtime_error("The input source is bad");
    }
    else
    {
        getline(cin, line);
    }

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
    else if (IsValidRomanDigit(curr_ch))
    {
        RomanNumeral romanNumber;
        this->input_str->putback(curr_ch);
        *this->input_str >> romanNumber;
        token = Token(eTokenTypeNumber, romanNumber.AsInt());
    }
    else if (curr_ch == '"')
    {
        string stringValue = this->get_string_value();
        *this->input_str >> curr_ch;
        if (curr_ch != '"' || ((*this->input_str).fail()))
        {
            token = Token(eTokenTypeInvalid);
        }
        else
        {
            token = Token(eTokenTypeString, stringValue, 0);
        }
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
    while (!this->input_str->eof() &&
           (isalpha(curr_ch) || is_digit(curr_ch) || is_underscore(curr_ch)))
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

string Token_stream::get_string_value()
{
    string value;
    char curr_ch;
    *this->input_str >> curr_ch;

    // the variable cannot begin with a digit due to the check in the get() function
    while (!this->input_str->eof() &&
           (curr_ch != '"'))
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

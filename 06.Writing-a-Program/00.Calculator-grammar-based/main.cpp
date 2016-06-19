#include <iostream>
#include <sstream>
#include <stdexcept>

#include "Token.h"
#include "Token_stream.h"

using namespace std;

/*
Implementing the grammar (parses arithmetic expressions):
    Expression:
        Term
        Expression '+' Term
        Expression '-' Term
    Term:
        Primary
        Term '*' Primary
        Term '/' Primary
        Term '%' Primary
    Primary:
        Number
        '(' Expression ')'
    Number:
        floating-point literal

*/

double expression();
double term();
double primary();

static Token_stream * token_str;

double expression()
{
    /*
        Expression:
            Term
            Expression '+' Term
            Expression '-' Term
    */

    double result = term();
    Token token;

    while (true)
    {
        token = token_str->get();

        switch (token.kind)
        {
            case eTokenTypePlus:
                result += term();
                break;
            case eTokenTypeMinus:
                result -= term();
                break;
            case eTokenTypeNull:
                return result;
            default:
                token_str->putback(token.kind);
                return result;
                break;
        }
    }

}

double term()
{
    /*
        Term:
            Primary
            Term '*' Primary
            Term '/' Primary
    */

    double result = primary();
    double divider;
    Token token;

    while (true)
    {
        token = token_str->get();

        switch (token.kind)
        {
            case eTokenTypeMultiply:
                result *= primary();
                break;
            case eTokenTypeDivide:
                divider = primary();
                if (divider != 0)
                {
                    result /= primary();
                }
                else
                {
                    throw runtime_error("Cannot divide by zero");
                }
                break;
            case eTokenTypeNull:
                return result;
            default:
                token_str->putback(token.kind);
                return result;
                break;
        }
    }

    return result;
}

double primary()
{
    /*
        Primary:
            Number
            '(' Expression ')'
    */

    Token tok = token_str->get();

    if (tok.kind == eTokenTypeLeftParan)
    {
        double result = expression();
        tok = token_str->get();

        if (tok.kind == eTokenTypeRightParan)
        {
            return result;
        }
        else
        {
            throw new runtime_error("Invalid parantheses");
        }
    }
    else if (tok.kind == eTokenTypeNumber)
    {
        return tok.value;
    }
    else
    {
        throw runtime_error("Invalid expression");
    }
}

int main()
{
    while (true)
    {
        double result;
        cout << "Expression: ";
        token_str = new Token_stream();

        try
        {
            result = expression();

            if (!token_str->eof())
            {
                throw runtime_error("Invalid parantheses");
            }
        }
        catch (runtime_error& e)
        {
            cout << e.what() << endl;
            delete token_str;
            return -1;
        }
        catch (exception& e)
        {
            cerr << e.what() << endl;
            cout << "An unhandled Exception occured" << endl;
            delete token_str;
            return -1;
        }

        delete token_str;
        cout << "Result: " << result << endl;
    }

    return 0;
}

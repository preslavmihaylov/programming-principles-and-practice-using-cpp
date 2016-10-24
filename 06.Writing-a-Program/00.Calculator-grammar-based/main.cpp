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

bool has_decimal_point(double val)
{
    return (val - (int)val > 0.00);
}

double factorial(int val)
{
    if (val == 1)
    {
        return 1;
    }

    return val * factorial(val - 1);
}

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
            Primary '!'
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
                    result /= divider;
                }
                else
                {
                    throw runtime_error("Cannot divide by zero");
                }
                break;
            case eTokenTypeFactorial:
                if (has_decimal_point(result))
                {
                    throw runtime_error("Factorial not defined for real numbers");
                }
                result = factorial(result);
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
            '{' Expression '}'
    */

    Token tok = token_str->get();

    switch (tok.kind)
    {
        case eTokenTypeLeftCurlyParan:
        case eTokenTypeLeftParan:
        {
            char startingParan = tok.kind;
            double result = expression();
            tok = token_str->get();

            if ((tok.kind == eTokenTypeRightParan && startingParan == eTokenTypeLeftParan) ||
                (tok.kind == eTokenTypeRightCurlyParan && startingParan == eTokenTypeLeftCurlyParan))
            {
                return result;
            }
            else
            {
                throw new runtime_error("Invalid parantheses");
            }
            break;
        }
        case eTokenTypeNumber:
            return tok.value;
            break;
        default:
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
            return -1;
        }
        catch (exception& e)
        {
            cerr << e.what() << endl;
            cerr << "An unhandled Exception occured" << endl;
            return -1;
        }

        delete token_str;
        cout << "Result: " << result << endl;
    }

    return 0;
}

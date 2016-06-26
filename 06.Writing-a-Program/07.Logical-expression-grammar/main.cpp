#include <iostream>
#include <stdexcept>

#include "Token_stream.h"
#include "Token.h"

using namespace std;

/*

Implementing the grammar for logical expressions:
Expression:
    Xor_Expr
    Expr '&' Expr
Xor_Expr:
    Or_Expr
    Xor_Expr '^' Xor_Expr
Or_Expr:
    Primary
    Or_Expr '|' Or_Expr
Primary:
    '!' Primary
    Variable
    '(' Expression ')'

*/

/* FUNCTION PROTOTYPES */
bool logical_expression();
bool and_expr();
bool xor_expr();
bool or_expr();
bool primary();

Token_stream * token_str;

bool logical_expression()
{
    return or_expr();
}

bool and_expr()
{
    bool result = primary();
    Token tok = token_str->get();

    switch (tok.kind)
    {
        case eTokenTypeAnd:
            result = and_expr() && result;
            break;
        default:
            token_str->putback(tok);
    }

    return result;
}

bool xor_expr()
{
    bool result = and_expr();
    Token tok = token_str->get();

    switch (tok.kind)
    {
        case eTokenTypeXor:
            result = xor_expr() ^ result;
            break;
        default:
            token_str->putback(tok);
    }

    return result;
}

bool or_expr()
{
    bool result = xor_expr();
    Token tok = token_str->get();

    switch (tok.kind)
    {
        case eTokenTypeOr:
            result = or_expr() || result;
            break;
        default:
            token_str->putback(tok);
    }

    return result;
}

bool primary()
{
    bool result = false;
    Token tok = token_str->get();
    bool invertResult = false;

    if (tok.kind == eTokenTypeNegation)
    {
        invertResult = true;
        tok = token_str->get();
    }

    if (tok.kind == eTokenTypeLeftParan)
    {
        result = logical_expression();
        tok = token_str->get();

        if (tok.kind != eTokenTypeRightParan)
        {
            throw runtime_error("Invalid parantheses");
        }
    }
    else if (tok.kind == eTokenTypeVariable)
    {
        result = tok.value;
    }

    return result ^ invertResult;
}

int main()
{
    while (true)
    {
        bool result;
        cout << "Expression: ";
        token_str = new Token_stream();

        try
        {
            result = logical_expression();
            cout << "Result: "
                 << (result == true ? "True" : "False")
                 << endl;
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
    }
}

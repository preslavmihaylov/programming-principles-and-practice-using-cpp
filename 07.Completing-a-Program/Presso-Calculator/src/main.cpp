#include <cmath>
#include <iostream>

#include "../headers/Symbol_table.h"
#include "../headers/Utilities.h"
#include "../headers/Token.h"
#include "../headers/Token_stream.h"

using namespace std;

/*
Implementing the grammar (parses arithmetic expressions):
    Statement:
        Declaration
        Expression
    Declaration:
        'let' Variable '=' Expression
        'const' Variable '=' Expression
        Variable '=' Expression
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
        Variable
        Number
        '-' Primary
        '+' Primary
        Function
        '{' Expression '}'
        '(' Expression ')'
    Function:
        Sqrt '(' Expression ')'
        Pow '(' Expression ',' Expression ')'
    Number:
        floating-point literal

*/

/* FUNCTION PROTOTYPES */
double statement();
double declaration(bool isDeclaration, bool isConstDeclaration);
double expression();
double term();
double primary();
double function_rule();
void calculate();

static Token_stream * token_str;

double statement()
{
    /*
        Statement:
            Declaration
            Expression
    */

    Token token = token_str->get();
    Token variable;
    double result;
    bool isConstDeclaration = false;
    bool isDeclaration = false;

    switch (token.kind)
    {
        case eTokenTypeConst:
        {
            isConstDeclaration = true;
        }
        case eTokenTypeLet:
        {
            isDeclaration = true;
        }
        // NOTE: Falls through from upper cases in order to avoid repetition
        case eTokenTypeVariable:
        {
            // If variable --> check if '=' is present.
            // If not --> Could be an expression starting with a variable
            // In both cases --> putback the extracted tokens for the next rule
            if (token.kind == eTokenTypeVariable)
            {
                Token nextToken = token_str->get();

                token_str->putback(nextToken);
                token_str->putback(token);

                if (nextToken.kind != eTokenTypeEqual)
                {
                    result = expression();
                    break;
                }
            }

            result = declaration(isDeclaration, isConstDeclaration);
            break;
        }
        default:
        {
            token_str->putback(token);
            result = expression();
            break;
        }
    }

    return result;
}

double declaration(bool isDeclaration, bool isConstDeclaration)
{
    /*
        Declaration:
            'let' Variable '=' Expression
            'const' Variable '=' Expression
            Variable '=' Expression
    */

    double result;
    Token variable = token_str->get();

    if (variable.kind == eTokenTypeVariable)
    {
        // Cannot declare an already declared variable
        if (isDeclaration && SYMBOL_TABLE.contains(variable.id))
        {
            throw runtime_error("Variable " + variable.id + " is already defined");
        }
        // Cannot modify an undeclared variable
        else if (!isDeclaration && !SYMBOL_TABLE.contains(variable.id))
        {
            throw runtime_error("Undeclared variable " + variable.id);
        }
        // Cannot modify a constant variable
        else if (!isDeclaration && SYMBOL_TABLE.is_constant(variable.id))
        {
            throw runtime_error("Cannot modify constant " + variable.id);
        }
        else
        {
            Token token = token_str->get();

            if (token.kind != eTokenTypeEqual)
            {
                throw runtime_error("Invalid statement");
            }

            result = expression();

            variable.value = result;

            SYMBOL_TABLE.set_value(variable.id, variable.value);

            if (isConstDeclaration)
            {
                SYMBOL_TABLE.set_const(variable.id);
            }
        }
    }
    else
    {
        throw runtime_error("Invalid statement");
    }

    return result;
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
            default:
                token_str->putback(token);
                return result;
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
            case eTokenTypeModulo:
            {
                int firstOp = (int)result;
                double secondOpDouble = primary();
                int secondOp = (int)secondOpDouble;

                if (firstOp != result ||
                    secondOp != secondOpDouble)
                {
                    throw runtime_error("Cannot use modulo operator on numbers of type double");
                }

                result = firstOp % secondOp;
                break;
            }
            case eTokenTypeFactorial:
                if (has_decimal_point(result))
                {
                    throw runtime_error("Factorial not defined for real numbers");
                }
                result = factorial(result);
                break;
            case eTokenTypeVariable:
                throw runtime_error("Invalid expression");
            default:
                token_str->putback(token);
                return result;
        }
    }

    return result;
}

double primary()
{
    /*
        Primary:
            Variable
            Number
            '-' Primary
            '+' Primary
            Sqrt '(' Expression ')'
            Pow '(' Expression ',' Expression ')'
            '{' Expression '}'
            '(' Expression ')'
    */

    double result;
    Token token = token_str->get();
    eTokenType expectedBracketKind;

    switch (token.kind)
    {
        case eTokenTypeMinus:
            result = -primary();
            break;
        case eTokenTypePlus:
            result = primary();
            break;
        case eTokenTypeLeftCurlyParan:
        case eTokenTypeLeftParan:
        {
            expectedBracketKind = get_expected_closing_paran(token.kind);

            result = expression();
            token = token_str->get();

            if (token.kind != expectedBracketKind)
            {
                throw runtime_error("Invalid parantheses");
            }

            break;
        }
        case eTokenTypeNumber:
            result = token.value;
            break;
        case eTokenTypeVariable:
            if (!SYMBOL_TABLE.contains(token.id))
            {
                throw runtime_error("Undeclared variable " + token.id);
            }

            result = SYMBOL_TABLE.get_value(token.id);
            break;
        case eTokenTypeSqrt:
        case eTokenTypePow:
        {
            token_str->putback(token);
            result = function_rule();
            break;
        }
        default:
            throw runtime_error("Invalid expression");
    }

    return result;
}

double function_rule()
{
    /*
        Function:
            Sqrt '(' Expression ')'
            Pow '(' Expression ',' Expression ')'
    */

    Token token = token_str->get();
    eTokenType expectedBracketKind;
    double result;

    switch (token.kind)
    {
        case eTokenTypeSqrt:
        {
            token = token_str->get();
            if (token.kind != eTokenTypeLeftParan &&
                token.kind != eTokenTypeLeftCurlyParan)
            {
                throw runtime_error("Invalid expression");
            }

            expectedBracketKind = get_expected_closing_paran(token.kind);

            double parameter = expression();
            token = token_str->get();

            if (token.kind != expectedBracketKind)
            {
                throw runtime_error("Invalid parantheses");
            }

            if (parameter < 0)
            {
                throw runtime_error("Cannot take sqrt of negative numbers");
            }
            result = sqrt(parameter);
            break;
        }
        case eTokenTypePow:
        {
            token = token_str->get();
            if (token.kind != eTokenTypeLeftParan &&
                token.kind != eTokenTypeLeftCurlyParan)
            {
                throw runtime_error("Invalid expression");
            }

            expectedBracketKind = get_expected_closing_paran(token.kind);

            double param1 = expression();
            token = token_str->get();

            if (token.kind != eTokenTypeComma)
            {
                throw runtime_error("Invalid number of arguments");
            }

            double param2 = expression();

            token = token_str->get();

            if (token.kind != expectedBracketKind)
            {
                throw runtime_error("Invalid parantheses");
            }

            result = pow(param1, param2);
            break;
        }
        default:
            throw runtime_error("Invalid expression");
    }

    return result;
}

void calculate()
{
    double result;
    Token currentToken;

    while (true)
    {
        bool isLineTerminated = false;
        cout << "> ";
        token_str = new Token_stream();

        try
        {
            currentToken = token_str->get();

            while (currentToken.kind != eTokenTypeNull)
            {
                switch (currentToken.kind)
                {
                    case eTokenTypeQuit:
                    case eTokenTypeExit:
                        return;
                    case eTokenTypeHelp:
                        print_help();
                        isLineTerminated = true;
                        break;
                    default:
                        token_str->putback(currentToken);
                        break;
                }

                if (isLineTerminated)
                {
                    break;
                }

                result = statement();
                currentToken = token_str->get();

                if (currentToken.kind != eTokenTypeSemicolon)
                {
                    throw runtime_error("Expression not terminated");
                }

                cout << "= " << result << endl;
                currentToken = token_str->get();
            }
        }
        catch (runtime_error & e)
        {
            cout << e.what() << endl;
            delete token_str;
            continue;
        }

        delete token_str;
    }
}

int main()
{

    try
    {
        calculate();
    }
    catch (exception& e)
    {
        cerr << e.what() << endl;
        delete token_str;
        return -1;
    }

    return 0;
}

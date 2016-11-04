#include <iostream>
#include <stdexcept>
#include <sstream>
#include <vector>
#include <algorithm>

#define NUM_KIND 8

using namespace std;

class Token
{
public:
    char kind;
    double value;
    Token(char ch)
        : kind(ch), value(0) {};
    Token(char ch, double val)
        : kind(ch), value(val) {};
    Token()
        : kind(0), value(0) {};
};

double eval(double lval, double rval, char op);
bool is_operator(char ch);
bool is_digit(char ch);
void read_tokens();
void print_tokens();
bool is_high_prior_op(char kind);
bool is_low_prior_op(char kind);
bool is_num_kind(char kind);
bool is_in_bounds(int index);
bool is_left_paran(char ch);
bool is_right_paran(char ch);
int find_right_paran(int start_i, int end_i);
int calculate_parans(int start_i, int end_i);
int calculate_operations(int start_i, int end_i, bool (*op_check_callback)(char));
double calculate_expression(int start_i, int end_i);
void init_calculator();

vector<Token> tokens;

double eval(double lval, double rval, char op)
{
    double result;

    result = lval;
    switch (op)
    {
        case '+':
            result += rval;
            break;
        case '-':
            result -= rval;
            break;
        case '*':
            result *= rval;
            break;
        case '/':
            result /= rval;
            break;
        default:
            throw runtime_error("Unknown operator");
        break;
    }

    return result;
}

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

void read_tokens()
{
    char curr_ch;
    double value;
    Token token;
    string expression;
    getline(cin, expression);
    istringstream input(expression);

    while (input >> curr_ch)
    {
        if (is_operator(curr_ch))
        {
            token = Token(curr_ch);
            tokens.push_back(token);
        }
        else if (is_digit(curr_ch))
        {
            input.putback(curr_ch);
            input >> value;
            token = Token(NUM_KIND, value);
            tokens.push_back(token);
        }
        else
        {
            throw runtime_error("Invalid input");
        }
    }
}

void print_tokens()
{
    for (int cnt = 0; cnt < tokens.size(); ++cnt)
    {
        cout << tokens[cnt].kind << " --> " << tokens[cnt].value << endl;
    }
}

bool is_high_prior_op(char kind)
{
    switch (kind)
    {
        case '*':
        case '/':
            return true;
        default:
            return false;
    }
}

bool is_low_prior_op(char kind)
{
    switch (kind)
    {
        case '+':
        case '-':
            return true;
        default:
            return false;
    }
}

bool is_num_kind(char kind)
{
    return kind == NUM_KIND;
}

bool is_in_bounds(int index)
{
    return index >= 0 && index < tokens.size();
}

bool is_left_paran(char ch)
{
    return ch == '(';
}

bool is_right_paran(char ch)
{
    return ch == ')';
}

int find_right_paran(int start_i, int end_i)
{
    int nested_parans_cnt = 0;

    for (int cnt = start_i; cnt <= end_i; ++cnt)
    {
        if (is_left_paran(tokens[cnt].kind))
        {
            ++nested_parans_cnt;
        }
        if (is_right_paran(tokens[cnt].kind))
        {
            if (nested_parans_cnt == 0)
            {
                return cnt;
            }
            else
            {
                --nested_parans_cnt;
            }
        }
    }

    return -1;
}

int calculate_parans(int start_i, int end_i)
{
    int left_paran_index;
    int right_paran_index;
    int deleted_parans = 0;
    int curr_deleted_parans;

    for (int cnt = start_i; cnt <= end_i; ++cnt)
    {
        if (is_left_paran(tokens[cnt].kind))
        {
            left_paran_index = cnt;
            right_paran_index = find_right_paran(left_paran_index + 1, end_i);
            if (right_paran_index == -1)
            {
                throw runtime_error("Invalid parantheses");
            }

            double result = calculate_expression(left_paran_index + 1, right_paran_index - 1);
            curr_deleted_parans = right_paran_index - left_paran_index;

            tokens.erase(tokens.begin() + (left_paran_index + 1),
                         tokens.begin() + (left_paran_index + 3));

            tokens[left_paran_index].kind = NUM_KIND;
            tokens[left_paran_index].value = result;

            deleted_parans += curr_deleted_parans;
            end_i -= curr_deleted_parans;
        }
        else if (is_right_paran(tokens[cnt].kind))
        {
            throw runtime_error("Invalid parantheses");
        }
    }

    return deleted_parans;
}

int calculate_operations(int start_i, int end_i, bool (*op_check_callback)(char))
{
    double result;
    int del_tokens_cnt = 0;

    for (int cnt = start_i; cnt <= end_i; ++cnt)
    {
        if (op_check_callback(tokens[cnt].kind))
        {
            if (is_in_bounds(cnt - 1) &&
                is_in_bounds(cnt + 1) &&
                is_num_kind(tokens[cnt - 1].kind) &&
                is_num_kind(tokens[cnt + 1].kind))
            {
                result = eval(tokens[cnt - 1].value, tokens[cnt + 1].value, tokens[cnt].kind);

                // NUM1, OP, NUM2
                // --> Remore OP and NUM2;
                // --> Set NUM1 as Result
                // --> Decrement index
                tokens.erase(tokens.begin() + cnt,
                             tokens.begin() + (cnt + 2));
                tokens[cnt - 1].kind = NUM_KIND;
                tokens[cnt - 1].value = result;
                --cnt;
                del_tokens_cnt += 2;
                end_i -= 2;
            }
            else
            {
                throw runtime_error("Invalid expression");
            }
        }
    }

    return del_tokens_cnt;
}

double calculate_expression(int start_i, int end_i)
{
    int del_tokens_cnt = 0;

    if (start_i > end_i)
    {
        throw runtime_error("Invalid expression");
    }

    del_tokens_cnt = calculate_parans(start_i, end_i);

    end_i -= del_tokens_cnt;

    del_tokens_cnt = calculate_operations(start_i, end_i, is_high_prior_op);

    end_i -= del_tokens_cnt;

    del_tokens_cnt = calculate_operations(start_i, end_i, is_low_prior_op);

    end_i -= del_tokens_cnt;

    if (tokens.size() <= start_i ||
        tokens[start_i].kind != NUM_KIND ||
        end_i != start_i)
    {
        throw runtime_error("Invalid expression");
    }

    return tokens[start_i].value;
}

void init_calculator()
{
    double result;
    cout << "Expression: ";

    tokens = {};
    read_tokens();
    //print_tokens();
    result = calculate_expression(0, tokens.size() - 1);


    cout << "Result: " << result << endl;
}

int main()
{
    while (true)
    {
        try
        {
            init_calculator();
        }
        catch (runtime_error e)
        {
            cerr << e.what() << endl;
            return -1;
        }
    }
    return 0;
}

#include <iostream>
#include <map>

using namespace std;

map<string, int> spelled_digits =
{
    {"zero", 0},
    {"one", 1},
    {"two", 2},
    {"three", 3},
    {"four", 4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"0", 0},
    {"1", 1},
    {"2", 2},
    {"3", 3},
    {"4", 4},
    {"5", 5},
    {"6", 6},
    {"7", 7},
    {"8", 8},
    {"9", 9},
};

bool is_valid_digit(string digit)
{
    return spelled_digits.find(digit) != spelled_digits.end();
}

int main()
{
    string first;
    string second;
    int digit1;
    int digit2;
    int result;
    string op;

    cout << "Input digits: ";
    cin >> first >> second;

    if (!is_valid_digit(first) || !is_valid_digit(second))
    {
        cout << "Invalid digits" << endl;
        return 1;
    }

    digit1 = spelled_digits[first];
    digit2 = spelled_digits[second];

    cout << "Input operator: ";
    cin >> op;

    if (op == "+")
    {
        result = digit1 + digit2;
    }
    else if (op == "-")
    {
        result = digit1 - digit2;
    }
    else if (op == "*")
    {
        result = digit1 * digit2;
    }
    else if (op == "/")
    {
        result = digit1 / digit2;
    }
    else
    {
        cout << "invalid operator" << endl;
        return 1;
    }

    cout << "Result: " << result << endl;

    return 0;
}

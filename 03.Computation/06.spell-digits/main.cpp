#include <iostream>
#include <vector>1

using namespace std;

static vector<string> spelled_digits =
{
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

int main()
{
    int digit;
    cout << "Enter digit: ";

    cin >> digit;

    if (digit < spelled_digits.size() && digit >= 0)
    {
        cout << "Spelled digit: " << spelled_digits[digit] << endl;
    }
    else
    {
        cout << "Invalid digit" << endl;
    }

    return 0;
}

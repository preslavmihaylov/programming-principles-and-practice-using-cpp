#include <iostream>

#define MAX_DIGITS_CNT 4

using namespace std;

static const string digit_values[MAX_DIGITS_CNT] = { "thousand", "hundred", "ten", "one" };

int main()
{
    int digits[MAX_DIGITS_CNT] = { 0 };
    int digit_index = MAX_DIGITS_CNT - 1;
    int cnt;

    string input;

    cin >> input;

    if (input.size() > 4)
    {
        cerr << "Max allowed digits: " + MAX_DIGITS_CNT << endl;
        return 1;
    }

    for (cnt = input.size() - 1; cnt >= 0; --cnt)
    {
        digits[digit_index--] = input[cnt] - '0';
    }

    bool firstValuePrinted = false;
    for (cnt = 0; cnt < MAX_DIGITS_CNT; ++cnt)
    {
        if (digits[cnt] > 0)
        {
            string digit_value = digit_values[cnt];

            if (digits[cnt] > 1)
            {
                digit_value += "s";
            }

            if (firstValuePrinted)
            {
                cout << "and ";
            }
            else
            {
                firstValuePrinted = true;
            }

            cout << digits[cnt] << " " << digit_value << " ";
        }
    }

    return 0;
}

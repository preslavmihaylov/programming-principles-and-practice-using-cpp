#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main()
{
    cout << "Input numbers: ";
    double number;
    int nums_to_sum;
    int result = 0;;
    vector<int> numbers;

    while (cin >> number)
    {
        if (trunc(number) == number)
        {
            numbers.push_back((int)number);
        }
        else
        {
            cerr << "Double number detected: " << number << endl;
        }
    }

    cout << "How many numbers to sum? ";
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //discard input

    cin >> nums_to_sum;

    if (nums_to_sum > numbers.size())
    {
        cerr << "Numbers to sum cannot be more than total numbers input" << endl;
        return -1;
    }

    for (int cnt = 0; cnt < nums_to_sum; ++cnt)
    {
        result += numbers[cnt];
    }

    cout << "Result: " << result << endl;
    return 0;
}

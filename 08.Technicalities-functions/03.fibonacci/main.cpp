#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void print(const string & outputLabel, const vector<int> & numbers)
{
    cout << outputLabel << endl;

    for (int cnt = 0; cnt < numbers.size(); ++cnt)
    {
        cout << numbers[cnt] << " ";
    }

    cout << endl;
}

void fibonacci(int x, int y, vector<int> & nums, int length)
{
    int first;
    int second;

    if (length < 0)
    {
        throw runtime_error("length cannot be negative");
    }

    if (length >= 1)
    {
        nums.push_back(x);
    }

    if (length >= 2)
    {
        nums.push_back(y);
    }

    for (int cnt = 2; cnt < length; ++cnt)
    {
        first = nums[nums.size() - 2];
        second = nums[nums.size() - 1];
        nums.push_back(first + second);
    }
}

int main()
{
    vector<int> fibonacciNums;

    fibonacci(1, 2, fibonacciNums, 6);
    print("fibonacci:", fibonacciNums);
    return 0;
}

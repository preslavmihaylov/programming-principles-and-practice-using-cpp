#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void input(vector<int> & numbers)
{
    int number;
    while (cin >> number)
    {
        numbers.push_back(number);
    }
}

int findMax(const vector<int> & numbers)
{
    int maxNum = INT_MIN;

    for (int cnt = 0; cnt < numbers.size(); ++cnt)
    {
        if (numbers[cnt] > maxNum)
        {
            maxNum = numbers[cnt];
        }
    }

    return maxNum;
}

void print(int number)
{
    cout << number << endl;
}

int main()
{
    vector<int> numbers;
    input(numbers);
    int maxNum = findMax(numbers);
    print(maxNum);

    return 0;
}

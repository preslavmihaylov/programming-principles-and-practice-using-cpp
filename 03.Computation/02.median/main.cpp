#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// We assume the vector is sorted
double get_median(vector<double> &numbers)
{
    if (numbers.size() % 2 == 1)
    {
        return numbers[numbers.size() / 2];
    }
    else
    {
        // average of middle two elements
        return (numbers[numbers.size() / 2] + numbers[numbers.size() / 2 - 1]) / 2;
    }
}

int main()
{
    vector<double> numbers;

    double input;

    while (cin>>input)
    {
        numbers.push_back(input);
    }

    sort(numbers.begin(), numbers.end());
    cout << get_median(numbers) << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>

using namespace std;

int main()
{
    cout << "Input numbers: ";
    double number;
    vector<double> numbers;
    vector<double> differences;

    while (cin >> number)
    {
        numbers.push_back((int)number);
    }

    // Reset input
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int cnt = 0; cnt < numbers.size() - 1; ++cnt)
    {
        differences.push_back(abs(numbers[cnt] - numbers[cnt + 1]));
    }

    cout << "Differences: ";
    for (int cnt = 0; cnt < differences.size(); ++cnt)
    {
        cout << differences[cnt] << " ";
    }

    cout << endl;
    return 0;
}

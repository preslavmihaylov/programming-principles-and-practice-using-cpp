#include <iostream>
#include <vector>

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

int main()
{
    vector<int> numbers = { 1, 2, 3, 4, 5 };
    print("NUMBERS", numbers);
    return 0;
}

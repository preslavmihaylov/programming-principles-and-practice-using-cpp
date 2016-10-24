#include <iostream>
#include <map>

using namespace std;

map<int, int> num_occurences;

void add_num(int num)
{
    if (num_occurences.find(num) == num_occurences.end())
    {
        num_occurences[num] = 0;
    }

    ++num_occurences[num];
}

void store_mode(int num, int * mode)
{
    if (num_occurences[*mode] < num_occurences[num])
    {
        *mode = num;
    }
}

int main()
{
    int value;
    int mode = 0;
    num_occurences[mode] = 0;

    while (cin >> value)
    {
        add_num(value);
        store_mode(value, &mode);
    }

    cout << "Mode: " << mode << endl;
    return 0;
}

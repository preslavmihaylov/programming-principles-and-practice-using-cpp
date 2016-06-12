#include <iostream>

using namespace std;

int spell_number(string input)
{
    int num;
    if (input == "zero")
    {
        num = 0;
    }
    else if (input == "one")
    {
        num = 1;
    }
    else if (input == "two")
    {
        num = 2;
    }
    else if (input == "three")
    {
        num = 3;
    }
    else if (input == "four")
    {
        num = 4;
    }
    else
    {
        num = -1;
    }

    return num;
}

int main()
{
    string input;

    cin >> input;
    int result = spell_number(input);

    if (result != -1)
    {
        cout << result << endl;
    }
    else
    {
        cout << "I don't know that number" << endl;
    }

    return 0;
}

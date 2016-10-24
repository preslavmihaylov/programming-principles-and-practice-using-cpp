#include <iostream>
#include <map>

using namespace std;

map<string, int> string_occurences;

void store_occurence(string input)
{
    if (string_occurences.find(input) == string_occurences.end())
    {
        string_occurences[input] = 0;
    }

    ++string_occurences[input];
}

void modify_mode(string input, string * mode)
{
    if (string_occurences[*mode] < string_occurences[input])
    {
        *mode = input;
    }
}

int main()
{
    string input;
    string mode = "";
    string_occurences[mode] = 0;

    string max_input = "";
    string min_input = "";

    while ((cin >> input) && input != "|")
    {
        store_occurence(input);
        modify_mode(input, &mode);

        if (input < min_input || min_input == "")
        {
            min_input = input;
        }

        if (input > max_input || max_input == "")
        {
            max_input = input;
        }
    }

    cout << "Mode: " << mode << endl;
    cout << "Max: " << max_input << endl;
    cout << "Min: " << min_input << endl;
    return 0;
}

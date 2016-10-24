#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void input(vector<string> & strings)
{
    // type Ctrl+Z to stop
    string text;
    while (cin >> text)
    {
        strings.push_back(text);
    }
}

void printStringInfo(const vector<string> & input,
                     vector<int> & charCounts,
                     string & smallest,
                     string & largest,
                     string & shortest,
                     string & longest)
{
    if (charCounts.size() != input.size())
    {
        assert(false);
    }

    cout << "Char counts:" << endl;
    for (int cnt = 0; cnt < charCounts.size(); ++cnt)
    {
        cout << input[cnt] << " -> " << charCounts[cnt] << endl;
    }

    cout << "Smallest: " << smallest << endl;
    cout << "Largest: " << largest << endl;
    cout << "Shortest: " << shortest << endl;
    cout << "Longest: " << longest << endl;
}

void computeStringInfo(const vector<string> & input,
                       vector<int> & charCounts,
                       string & smallest,
                       string & largest,
                       string & shortest,
                       string & longest)
{
    charCounts.resize(input.size());
    smallest = "";
    largest = "";
    shortest = "";
    longest = "";

    for (int cnt = 0; cnt < input.size(); ++cnt)
    {
        charCounts[cnt] = input[cnt].size();

        if (input[cnt] > largest)
        {
            largest = input[cnt];
        }

        if (input[cnt] < smallest || smallest == "")
        {
            smallest = input[cnt];
        }

        if (input[cnt].size() < shortest.size() || shortest == "")
        {
            shortest = input[cnt];
        }

        if (input[cnt].size() > longest.size())
        {
            longest = input[cnt];
        }
    }
}

void findMinMax(const vector<string> & input, string & smallest, string & largest)
{
    smallest = "";
    largest = "";
}

int main()
{
    vector<string> strings;
    vector<int> charCounts;
    string smallest;
    string largest;
    string shortest;
    string longest;

    input(strings);
    computeStringInfo(strings, charCounts, smallest, largest, shortest, longest);
    printStringInfo(strings, charCounts, smallest, largest, shortest, longest);
    return 0;
}

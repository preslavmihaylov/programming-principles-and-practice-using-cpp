#include <iostream>
#include <cassert>
#include <vector>
#include <algorithm>

using namespace std;

void input(vector<string> & names, vector<int> & ages)
{
    string name;
    int age;

    while (cin >> name && cin >> age)
    {
        if (find(names.begin(), names.end(), name) != names.end())
        {
            throw runtime_error("duplicate name");
        }

        names.push_back(name);
        ages.push_back(age);
    }
}

void print(string label, const vector<string> & names, const vector<int> & ages)
{
    if (names.size() != ages.size())
    {
        assert(false);
    }

    cout << label << endl;
    for (int cnt = 0; cnt < names.size(); ++cnt)
    {
        cout << names[cnt] << " -> " << ages[cnt] << endl;
    }

    cout << endl;
}

int findIndex(vector<string> & sortedNames, vector<string> & origNames, int initIndex)
{
    if (origNames.size() != sortedNames.size())
    {
        assert(false);
    }

    for (int cnt = 0; cnt < sortedNames.size(); ++cnt)
    {
        if (sortedNames[cnt] == origNames[initIndex])
        {
            return cnt;
        }
    }

    assert(false);
    return -1;
}

void sortPairs(vector<string> & names, vector<int> & ages)
{
    if (names.size() != ages.size())
    {
        assert(false);
    }

    vector<string> origNames = names;
    vector<int> origAges = ages;
    sort(names.begin(), names.end());

    for (int cnt = 0; cnt < origAges.size(); ++cnt)
    {
        int newIndex = findIndex(names, origNames, cnt);
        ages[newIndex] = origAges[cnt];
    }
}

int main()
{
    vector<string> names;
    vector<int> ages;
    input(names, ages);
    print("BEFORE", names, ages);
    sortPairs(names, ages);
    print("AFTER", names, ages);
    return 0;
}

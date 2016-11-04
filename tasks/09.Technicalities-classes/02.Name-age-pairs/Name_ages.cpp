#include "Name_ages.h"
#include <stdexcept>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

bool operator==(const Name_ages& firstNameAges, const Name_ages& secondNameAges)
{
    if ((firstNameAges.names.size() != secondNameAges.names.size()) ||
        (firstNameAges.ages.size() != secondNameAges.ages.size()))
    {
        return false;
    }

    for (int cnt = 0; cnt < firstNameAges.names.size(); ++cnt)
    {
        if (firstNameAges.names[cnt] != secondNameAges.names[cnt])
        {
            return false;
        }

        if (firstNameAges.ages[cnt] != secondNameAges.ages[cnt])
        {
            return false;
        }
    }

    return true;
}

bool operator!=(const Name_ages& firstNameAges, const Name_ages& secondNameAges)
{
    return !(firstNameAges==secondNameAges);
}

std::ostream& operator<<(std::ostream& os, const Name_ages& nameAges)
{
    if (nameAges.names.size() != nameAges.ages.size())
    {
        assert(false);
        return os;
    }

    int namesCount = nameAges.names.size();

    for (int cnt = 0; cnt < namesCount; ++cnt)
    {
        os << nameAges.names[cnt] << " -> " << nameAges.ages[cnt] << endl;
    }

    return os;
}

void Name_ages::ReadNames()
{
    if (!this->areNamesInput)
    {
        string name;
        int namesCount;
        cout << "How many names will you input?: ";
        cin >> namesCount;

        for (int cnt = 0; cnt < namesCount; ++cnt)
        {
            cin >> name;
            this->names.push_back(name);
        }

        this->areNamesInput = true;
    }
    else
    {
        throw runtime_error("names are already input");
    }
}

void Name_ages::ReadAges()
{
    if (this->areNamesInput && !this->areAgesInput)
    {
        int age;
        int namesCount = this->names.size();
        for (int cnt = 0; cnt < namesCount; ++cnt)
        {
            cin >> age;
            this->ages.push_back(age);
        }

        this->areAgesInput = false;
    }
    else
    {
        throw runtime_error("Cannot read ages");
    }
}

void Name_ages::Sort()
{
    vector<string> oldNames = this->names;
    vector<int> oldAges = this->ages;

    sort(this->names.begin(), this->names.end());

    for (int oldNameIndex = 0; oldNameIndex < oldNames.size(); ++oldNameIndex)
    {
        for (int newNameIndex = 0; newNameIndex < this->names.size(); ++newNameIndex)
        {
            if (this->names[newNameIndex] == oldNames[oldNameIndex])
            {
                this->ages[newNameIndex] = oldAges[oldNameIndex];
                break;
            }
        }
    }
}

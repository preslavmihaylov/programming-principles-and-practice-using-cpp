#include <iostream>
#include <cstring>

#define MAX_STR_LENGTH 100

#define mSTR_EQUALS(str1, str2) (strcmp(str1, str2) == 0)

enum eDaysOfWeek
{
    eMonday,
    eTuesday,
    eWednesday,
    eThursday,
    eFriday,
    eSaturday,
    eSunday,
    eDaysOfWeekNb
};

using namespace std;

int sums[eDaysOfWeekNb];

void to_lower(char * key)
{
    int cnt = 0;
    while (key[cnt] != '\0')
    {
        if (key[cnt] >= 'A' && key[cnt] <= 'Z')
        {
            key[cnt] -= 'A';
            key[cnt] += 'a';
        }

        ++cnt;
    }
}

void print_output()
{
    cout << "MONDAY: " << sums[eMonday] << endl;
    cout << "TUESDAY: " << sums[eTuesday] << endl;
    cout << "WEDNESDAY: " << sums[eWednesday] << endl;
    cout << "THURSDAY: " << sums[eThursday] << endl;
    cout << "FRIDAY: " << sums[eFriday] << endl;
    cout << "SATURDAY: " << sums[eSaturday] << endl;
    cout << "SUNDAY: " << sums[eSunday] << endl;
}

bool process_input(char * key, int value)
{
    to_lower(key);

    if (mSTR_EQUALS(key, "monday") ||
        mSTR_EQUALS(key, "mon"))
    {
        sums[eMonday] += value;
    }
    else if (mSTR_EQUALS(key, "tuesday") ||
        mSTR_EQUALS(key, "tue"))
    {
        sums[eTuesday] += value;
    }
    else if (mSTR_EQUALS(key, "wednesday") ||
        mSTR_EQUALS(key, "wed"))
    {
        sums[eWednesday] += value;
    }
    else if (mSTR_EQUALS(key, "thursday") ||
        mSTR_EQUALS(key, "thu"))
    {
        sums[eThursday] += value;
    }
    else if (mSTR_EQUALS(key, "friday") ||
        mSTR_EQUALS(key, "fri"))
    {
        sums[eFriday] += value;
    }
    else if (mSTR_EQUALS(key, "saturday") ||
        mSTR_EQUALS(key, "say"))
    {
        sums[eSaturday] += value;
    }
    else if (mSTR_EQUALS(key, "sunday") ||
        mSTR_EQUALS(key, "sun"))
    {
        sums[eSunday] += value;
    }
    else
    {
        return false;
    }

    return true;
}



int main()
{
    char key[MAX_STR_LENGTH];
    int value;
    bool valid_input;

    while ((cin >> key) && (cin >> value))
    {
        valid_input = process_input(key, value);

        if (!valid_input)
        {
            cout << "Invalid input. Try again" << endl;
        }
    }

    print_output();
    return 0;
}

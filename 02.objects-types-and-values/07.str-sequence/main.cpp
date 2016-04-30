#include <iostream>

using namespace std;

void swp(string * first, string * second)
{
    string temp = *first;
    *first = *second;
    *second = temp;
}

void orderAsc(string * first, string * second)
{
    if (*first < *second)
    {
        // already ordered
    }
    else
    {
        swp(first, second);
    }
}

void orderAsc(string * first, string * second, string * third)
{
    if (*first < *second && *first < *third)
    {
        // first is in order
    }
    else if (*second < *first && *second < *third)
    {
        // put second at first pos
        swp(first, second);
    }
    else
    {
        // put third in first pos
        swp(first, third);
    }

    // order leftover numbers
    orderAsc(second, third);
}

void readInput(string * first, string * second, string * third)
{
    cin >> *first >> *second >> *third;
}

int main()
{
    string first, second, third;
    readInput(&first, &second, &third);
    orderAsc(&first, &second, &third);

    cout << first << " " << second << " " << third << endl;


    return 0;
}

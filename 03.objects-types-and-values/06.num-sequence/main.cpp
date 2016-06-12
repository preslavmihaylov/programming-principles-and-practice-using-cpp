#include <iostream>

using namespace std;

void swp(int * first, int * second)
{
    *first ^= *second;
    *second ^= *first;
    *first ^= *second;
}

void orderAsc(int * first, int * second)
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

void orderAsc(int * first, int * second, int * third)
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

void readInput(int * first, int * second, int * third)
{
    cin >> *first >> *second >> *third;
}

int main()
{
    int first, second, third;
    readInput(&first, &second, &third);
    orderAsc(&first, &second, &third);

    cout << first << " " << second << " " << third << endl;


    return 0;
}

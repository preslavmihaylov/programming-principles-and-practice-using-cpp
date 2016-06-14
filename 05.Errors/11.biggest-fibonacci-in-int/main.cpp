#include <iostream>
#include <limits.h>

using namespace std;

bool is_overflow(int first, int second)
{
    return ((second > 0) && (first > (INT_MAX - second)));
}

int main()
{

    int first = 1;
    int second = 1;
    int temp;
    int n = 2;

    while (!is_overflow(first, second))
    {
        ++n;
        temp = first + second;
        first = second;
        second = temp;
    }

    cout << "Index: " << n << endl;
    cout << "Fibonacci number: " << second << endl;
    return 0;
}

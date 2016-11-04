#include <iostream>

using namespace std;

int approxMaxIntUsingFibonacci()
{
    int temp;
    int first = 1;
    int second = 1;

    while (first <= second)
    {
        temp = second;
        second = first + second;
        first = temp;
    }

    return first;
}

int main()
{
    int res = approxMaxIntUsingFibonacci();
    cout << "Max int approximated: " << res << endl;
    return 0;
}

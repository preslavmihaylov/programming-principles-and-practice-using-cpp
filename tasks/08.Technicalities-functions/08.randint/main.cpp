#include <iostream>
#include <climits>
#include "cust_randint.h"

using namespace std;

void generateRandNums(int times)
{
    for (int cnt = 0; cnt < times; ++cnt)
    {
        cout << cust_randint() << endl;
    }
}

void generateRandNums(int start, int finish, int times)
{

    cout << "rand nums in range [" << start << ", " << finish << ")" << endl;
    for (int cnt = 0; cnt < times; ++cnt)
    {
        cout << cust_randInRange(start, finish) << endl;
    }
}

int main()
{
    generateRandNums(5);
    generateRandNums(0, 10, 5);

    return 0;
}

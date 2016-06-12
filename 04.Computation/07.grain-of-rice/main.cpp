#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int grain_cnt;
    cout << "How many grain do you want? ";
    cin >> grain_cnt;

    int collected_grain = 0;
    int squares_cnt = 0; // ceil(log10(grain_cnt) / log10(2)) + 1;
    int two_pow = 1;

    while (collected_grain < grain_cnt)
    {
        collected_grain += two_pow;
        two_pow *= 2;
        ++squares_cnt;
    }

    cout << "You will need " << squares_cnt << " squares of chess" << endl;

    // Second solution using log
    // log2(n) = log10(n) / log10(2) - log property
    squares_cnt =  ceil(log10(grain_cnt) / log10(2));

    cout << "Calculated using log: " << squares_cnt << endl;


    return 0;
}

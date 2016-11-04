#include <iostream>
#include "Money.h"

using namespace std;

int main()
{
    Money money1(1.555, Money::USD);
    Money money2(2, Money::BGN);

    cout << 1.555 << "USD" << " -> " << money1 << endl;
    cout << 2 << "BGN" << " -> " << money2 << endl;

    Money res = money1 + money2;
    Money res1 = money1 - money2;
    cout << "money1 + money2 = " << res << endl;
    cout << "money1 - money2 = " << res1 << endl;

    Money money3(2, (Money::Currency)5);
    return 0;
}

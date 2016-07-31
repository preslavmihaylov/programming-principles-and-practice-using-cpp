#include <iostream>
#include "Date.h"

using namespace std;
using namespace Chrono;

int main()
{
    Date d1(2000, Date::Month(13), 1);
    Date d2;

    cout << d1 << endl;
    cin >> d2;
    cout << d2 << endl;
    return 0;
}

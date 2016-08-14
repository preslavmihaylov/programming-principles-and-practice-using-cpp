#include <iostream>
#include "Date.h"

using namespace std;
using namespace Chrono;

int main()
{
    Date d1(2000, Date::Month(12), 1);
    Date d2(2001, Date::jan, 1);

    cout << d1 << endl;
    //cin >> d2;
    //cout << d2 << endl;

    for (int cnt = 0; cnt < 366; ++cnt)
    {
        d2.add_day(1);
        cout << d2 << ", ";
    }

    d2.add_day(365);
    cout << d2 << endl;
    d2.add_day(365);
    cout << d2 << endl;
    d2.add_day(365);
    cout << d2 << endl;
    d2.add_day(30);
    cout << d2 << endl;
    d2.add_day(-1);
    cout << d2 << endl;

    cout << "Day of week: " << day_of_week(d2) << endl;
    cout << "Next sunday: " << next_Sunday(d2) << endl;
    cout << "Next weekday: " << next_weekday(d2) << endl;
    return 0;
}

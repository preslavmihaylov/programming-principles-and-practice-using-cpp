#include <iostream>

using namespace std;

#define MILES_KM_RATIO 1.609

int main()
{
    double km;
    double miles;

    cout << "Please enter miles: ";

    cin >> miles;

    km = miles * MILES_KM_RATIO;

    cout << "There are " << km << " km in " << miles << " miles" << endl;

    return 0;
}

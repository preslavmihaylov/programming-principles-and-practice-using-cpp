#include <iostream>
#include "Name_ages.h"

using namespace std;

int main()
{
    Name_ages data;
    data.ReadNames();
    data.ReadAges();

    cout << "Before sort" << endl;
    cout << data;
    data.Sort();

    cout << "After sort" << endl;
    cout << data;

    Name_ages data2;
    cout << "Second name_ages pair" << endl;
    data2.ReadNames();
    data2.ReadAges();
    data2.Sort();

    cout << "Are equal? " << (data == data2) << endl;
    cout << "Are different? " << (data != data2) << endl;
    return 0;
}

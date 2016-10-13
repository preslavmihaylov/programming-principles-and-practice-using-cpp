#include <iostream>
#include <stdexcept>
#include "RomanNumeral.h"

using namespace std;

int main()
{
    string input;

    cin >> input;
    while (input != "end")
    {
        try
        {
            RomanNumeral romanNumeral(input);
            cout << "Roman: " << romanNumeral << " Int: " << romanNumeral.AsInt() << endl;
        }
        catch (runtime_error& e)
        {
            cout << e.what() << endl;
        }

        cin >> input;
    }
    return 0;
}

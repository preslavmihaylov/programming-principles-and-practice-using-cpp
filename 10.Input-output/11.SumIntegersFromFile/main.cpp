#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

#define INPUT_FILENAME ("data.txt")

int main()
{
    ifstream inputStream(INPUT_FILENAME);
    string input;
    int sum = 0;
    int currentNum;

    while (!inputStream.eof())
    {
        inputStream >> input;
        if (inputStream.bad())
        {
            cout << "The input is bad" << endl;
            return 1;
        }
        else if (inputStream.fail())
        {
            cout << "Something unexpected happened" << endl;
            return 1;
        }
        else
        {
            currentNum = atoi(input.c_str());
            sum += currentNum;
        }
    }

    cout << "Sum: " << sum << endl;

    return 0;
}

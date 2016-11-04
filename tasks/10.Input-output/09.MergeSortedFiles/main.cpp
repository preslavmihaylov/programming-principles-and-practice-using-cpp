#include <iostream>
#include <fstream>

using namespace std;

#define FIRST_FILENAME ("first.txt")
#define SECOND_FILENAME ("second.txt")
#define OUTPUT_FILENAME ("output.txt")

int main()
{
    string firstValue;
    string secondValue;
    ifstream firstFileStream(FIRST_FILENAME);
    ifstream secondFileStream(SECOND_FILENAME);
    ofstream outputFileStream(OUTPUT_FILENAME);

    if (!firstFileStream.good())
    {
        cout << "Couldn't open file: " << FIRST_FILENAME << endl;
    }

    if (!secondFileStream.good())
    {
        cout << "Couldn't open file: " << SECOND_FILENAME << endl;
    }

    if (!outputFileStream.good())
    {
        cout << "Couldn't open file: " << OUTPUT_FILENAME << endl;
    }

    firstFileStream >> firstValue;
    secondFileStream >> secondValue;
    while (!firstFileStream.fail() && !secondFileStream.fail())
    {
        if (firstValue > secondValue)
        {
            outputFileStream << secondValue << endl;
            secondFileStream >> secondValue;
        }
        else if (firstValue <= secondValue)
        {
            outputFileStream << firstValue << endl;
            firstFileStream >> firstValue;
        }
    }

    while (!firstFileStream.fail())
    {
            outputFileStream << firstValue << endl;
            firstFileStream >> firstValue;
    }

    while (!secondFileStream.fail())
    {
            outputFileStream << secondValue << endl;
            secondFileStream >> secondValue;
    }

    return 0;
}

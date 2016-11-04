#include <iostream>

#include "Year.h"
#include <fstream>

#define INPUT_FILENAME ("data.txt")

using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;

    string in_filename;
    string out_filename;
    cout << "Please enter input filename: ";
    cin >> in_filename;

    inputFile.open(in_filename.c_str());
    if (!inputFile)
    {
        cout << "Cannot open input file" << endl;
        return 1;
    }

    cout << "Please enter output filename: ";
    cin >> out_filename;
    outputFile.open(out_filename.c_str());
    if (!outputFile)
    {
        cout << "Cannot open output file" << endl;
        return 1;
    }

    while (inputFile.good())
    {
        Year year;
        inputFile >> year;
        if (!inputFile.eof() && inputFile.fail())
        {
            outputFile << "Failed reading a year" << endl;
            break;
        }
        else if (!inputFile.eof())
        {
            outputFile << year << endl;
        }
    }

    return 0;
}

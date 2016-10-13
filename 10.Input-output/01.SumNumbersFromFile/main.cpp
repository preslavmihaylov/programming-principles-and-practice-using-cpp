#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int sum = 0;
    int currentNum;
    ifstream inputFile("mydata.txt");
    inputFile.exceptions(inputFile.exceptions()|ios_base::badbit);

    while (!inputFile.eof())
    {
        inputFile >> currentNum;
        if (inputFile.fail())
        {
            cout << "Invalid number found. Exiting program" << endl;
            return 1;
        }

        sum += currentNum;
    }

    cout << "The sum of the numbers is: " << sum << endl;

    return 0;
}

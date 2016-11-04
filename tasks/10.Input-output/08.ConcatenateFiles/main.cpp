#include <iostream>
#include <fstream>

using namespace std;

#define FIRST_FILENAME ("first.txt")
#define SECOND_FILENAME ("second.txt")
#define RESULT_FILENAME ("result.txt")

void DumpContents(ifstream& inputFileStream, ostream& outputFileStream)
{
    string line;
    while (!inputFileStream.eof())
    {
        std::getline(inputFileStream, line);
        outputFileStream << line << endl;
    }
}

int main()
{
    ifstream firstFileStream;
    ifstream secondFileStream;
    ofstream resultFileStream(RESULT_FILENAME);
    if (!resultFileStream.good())
    {
        cout << "Couldn't open file: " << RESULT_FILENAME << endl;
    }

    firstFileStream.open(FIRST_FILENAME);
    if (!firstFileStream.good())
    {
        cout << "Couldn't open file: " << FIRST_FILENAME << endl;
    }

    DumpContents(firstFileStream, resultFileStream);

    firstFileStream.close();
    secondFileStream.open(SECOND_FILENAME);
    if (!secondFileStream.good())
    {
        cout << "Couldn't open file: " << SECOND_FILENAME << endl;
    }

    DumpContents(secondFileStream, resultFileStream);
    return 0;
}

#include <iostream>
#include <fstream>
#include <strstream>

using namespace std;

#define INPUT_FILENAME ("data.txt")

static bool StringContainsWord(string line, string word)
{
    int lineIndex;
    int wordIndex;
    bool matches;

    for (lineIndex = 0; lineIndex < line.size() && !matches; ++lineIndex)
    {
        matches = true;
        for (wordIndex = 0; wordIndex < word.size() && matches; ++wordIndex)
        {
            if (word[wordIndex] != line[lineIndex + wordIndex])
            {
                matches = false;
            }
        }
    }

    return matches;
}

int main()
{
    ifstream inputStream(INPUT_FILENAME);
    string inputLine;
    string word;
    int lineNumber = 0;

    while (!inputStream.eof())
    {
        getline(inputStream, inputLine);
        if (inputStream.bad())
        {
            cout << "The input is bad" << endl;
        }
        else if (inputStream.fail())
        {
            cout << "Something unexpected happened" << endl;
        }

        ++lineNumber;
        if (StringContainsWord(inputLine, "MAIKA"))
        {
            cout << lineNumber << " " << inputLine << endl;
        }
    }

    return 0;
}

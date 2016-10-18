#include "Year.h"

#include <stdexcept>
#include <climits>

using namespace std;

/* Local function prototypes */
static bool IsValidYear(int year);

istream& operator>>(istream& inputStream, Year& year)
{
    char paran1;
    char paran2;
    string yearKeyword;
    int yearOfData;
    Month currentMonth;
    inputStream >> paran1;
    if (inputStream.eof())
    {
        return inputStream;
    }

    if (paran1 != '{') // Is it a year?
    {
        inputStream.unget();
        inputStream.clear(ios_base::failbit);
        return inputStream;
    }

    inputStream >> yearKeyword;
    if (yearKeyword != "year")
    {
        inputStream.clear(ios_base::failbit);
    }

    inputStream >> yearOfData;
    if (inputStream.good())
    {
        if (!IsValidYear(yearOfData))
        {
            inputStream.clear(ios_base::failbit);
        }
        else
        {
            year.yearOfData = yearOfData;
        }
    }

    while ((inputStream >> paran2) && paran2 != '}')
    {
        currentMonth = Month(); // Initialize month with default values
        inputStream.unget();
        inputStream >> currentMonth;
        if (inputStream.good() && !year.IsDuplicateMonth(currentMonth))
        {
            year.months.push_back(currentMonth);
        }
        else
        {
            inputStream.clear(ios_base::failbit); // If the month is duplicate, set fail bit up
            break;
        }
    }

    if (inputStream.fail() ||
        paran2 != '}')
    {
        inputStream.clear();
        while (inputStream >> currentMonth);
        inputStream.clear();
        inputStream.ignore(INT_MAX, '}');
        inputStream.clear(ios_base::failbit);
    }

    return inputStream;
}

ostream& operator<<(ostream& outputStream, const Year& year)
{
    outputStream << "Year: " << year.yearOfData << ":";
    for (int i = 0; i < year.months.size(); ++i)
    {
        outputStream << endl << " - " << year.months[i];
    }

    return outputStream;
}

static bool IsValidYear(int year)
{
    return year >= 1970 && year < 2300;
}

Year::Year(int year)
{
    if (IsValidYear(year))
    {
        this->yearOfData = year;
    }
    else
    {
        throw runtime_error("Invalid year");
    }
}

bool Year::IsDuplicateMonth(const Month& month)
{
    for (int i = 0; i < this->months.size(); ++i)
    {
        if (this->months[i].GetMonthIndex() == month.GetMonthIndex())
        {
            return true;
        }
    }

    return false;
}

#include "Month.h"

#define INVALID_ID (-1)

#include <stdexcept>
#include <climits>

using namespace std;

vector<string> monthIds =
{
    "jan",
    "feb",
    "mar",
    "apr",
    "may",
    "jun",
    "jul",
    "aug",
    "sep",
    "oct",
    "nov",
    "dec"
};

/* Local function prototypes */
static int ConvertMonthIdToIndex(string monthId);
static string ConvertMonthIndexToId(int id);

istream& operator>>(istream& inputStream, Month& month)
{
    char paran1;
    char paran2;
    string monthId;
    string monthKeyword;
    int monthIndex;
    int invalidReadings = 0;
    Reading currentReading;

    inputStream >> paran1;
    if (inputStream.eof())
    {
        return inputStream;
    }

    if (paran1 != '{') // Is it a month?
    {
        inputStream.unget();
        inputStream.clear(ios_base::failbit);
        return inputStream;
    }

    inputStream >> monthKeyword;

    // Declaration starts with keyword 'month'
    if (monthKeyword != "month")
    {
        inputStream.clear(ios_base::failbit);
    }

    inputStream >> monthId;

    if (inputStream.good())
    {
        monthIndex = ConvertMonthIdToIndex(monthId);
        if (monthIndex == INVALID_ID)
        {
            inputStream.clear(ios_base::failbit);
        }
        else
        {
            month.monthIndex = monthIndex;
        }
    }

    while ((inputStream >> paran2) && paran2 != '}')
    {
        inputStream.unget();
        inputStream >> currentReading;
        if (inputStream.good() && !month.IsDuplicateReading(currentReading))
        {
            month.readings.push_back(currentReading);
        }
        else
        {
            inputStream.clear(ios_base::failbit); // If the reading is duplicate, set fail bit up
            break;
        }
    }

    if (inputStream.fail() ||

        paran2 != '}')
    {
        inputStream.clear();
        inputStream.ignore(INT_MAX, '}');
        inputStream.clear(ios_base::failbit);
    }

    return inputStream;
}

ostream& operator<<(ostream& outputStream, const Month& month)
{
    outputStream << "Month: " << ConvertMonthIndexToId(month.monthIndex);
    for (int i = 0; i < month.readings.size(); ++i)
    {
        outputStream << endl << "Reading: " << month.readings[i];
    }

    outputStream;
    return outputStream;
}

static string ConvertMonthIndexToId(int id)
{
    if (id >= 0 && id < 12)
    {
        return monthIds[id];
    }
    else
    {
        return "";
    }
}

static int ConvertMonthIdToIndex(string monthId)
{
    for (int i = 0; i < monthIds.size(); ++i)
    {
        if (monthId == monthIds[i])
        {
            return i;
        }
    }

    return INVALID_ID;
}

Month::Month(string monthId)
{
    int monthIndex = ConvertMonthIdToIndex(monthId);

    if (monthIndex == INVALID_ID)
    {
        throw runtime_error("Invalid month id");
    }

    this->monthIndex = monthIndex;
}

bool Month::IsDuplicateReading(const Reading& reading)
{
    for (int i = 0; i < this->readings.size(); ++i)
    {
        if (this->readings[i].GetDay() == reading.GetDay())
        {
            return true;
        }
    }

    return false;
}

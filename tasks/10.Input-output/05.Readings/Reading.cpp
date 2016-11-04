#include "Reading.h"
#include <stdexcept>
#include <climits>

using namespace std;

/* Local function prototypes */
static bool IsValidDay(int day);
static bool IsValidHour(int hour);
static bool IsValidTemp(double temp);

ostream& operator<<(ostream& outputStream, const Reading& reading)
{
    outputStream << "Day: " << reading.day << " " << "Hour: " << reading.hour << " " << "Temp: " << reading.temperature;
    return outputStream;
}

istream& operator>>(istream& inputStream, Reading& reading)
{
    int day;
    int hour;
    double temperature;
    char paran1;
    char paran2;

    inputStream >> paran1;
    if (inputStream.eof())
    {
        return inputStream;
    }

    if (paran1 != '(') // Is it a reading?
    {
        inputStream.unget();
        inputStream.clear(ios_base::failbit);
        return inputStream;
    }

    inputStream >> day >> hour >> temperature >> paran2;

    if (inputStream.good() &&
        paran1 == '(' &&
        paran2 == ')' &&
        IsValidDay(day) &&
        IsValidHour(hour) &&
        IsValidTemp(temperature))
    {
        reading.day = day;
        reading.hour = hour;
        reading.temperature = temperature;
    }
    else
    {
        if (paran2 != ')')
        {
            inputStream.ignore(INT_MAX, ')');
        }

        inputStream.clear(ios_base::failbit);
    }

    return inputStream;
}

static bool IsValidDay(int day)
{
    return (day >= 1 && day <= 31);
}

static bool IsValidHour(int hour)
{
    return (hour >= 0 && hour <= 23);
}

static bool IsValidTemp(double temperature)
{
    return (temperature >= -273.15); // no upper bound
}

Reading::Reading(int day, int hour, double temperature)
{
    if (IsValidDay(day) &&
        IsValidHour(hour) &&
        IsValidTemp(temperature))
    {
        this->day = day;
        this->hour = hour;
        this->temperature = temperature;
    }
    else
    {
        throw runtime_error("Invalid reading");
    }
}

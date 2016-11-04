#include <iostream>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <cmath>

using namespace std;

#define RAW_TEMPS_FILENAME ("raw_temps.txt")
#define INVALID_HOUR (-1)
#define INVALID_TEMP (-2000)

struct Reading
{
    int hour; // [0-23]
    double temp;

    Reading(int hour, int temp)
        : hour(hour), temp(temp) {};
};

ostream& operator<<(ostream& output, const Reading& reading)
{
    output << reading.hour << ' ' << (roundf(reading.temp * 10) / 10);
    return output;
}

istream& operator>>(istream& input, Reading& reading)
{
    char measure;
    input >> reading.hour;
    if (input.eof())
    {
        return input;
    }
    else if (input.fail() || ((reading.hour < 0) || (reading.hour > 23)))
    {
        throw runtime_error("Invalid hour");
    }

    input >> reading.temp;
    if (input.fail())
    {
        throw runtime_error("Invalid temperature");
    }

    while (input >> measure && (measure == ' ' || measure == '\t'));
    if (input.fail())
    {
        throw runtime_error("Invalid measure");
    }

    if (measure == 'c')
    {
        reading.temp = (reading.temp * 1.8) + 32;
    }
    else if (measure == 'f')
    {
        // internally stored as fahrenheit by definition
    }
    else
    {
        throw runtime_error("Invalid measure");
    }

    return input;
}

bool ReadInput(vector<Reading>& readings, istream& inputStream)
{
    while (true)
    {
        Reading reading(INVALID_HOUR, INVALID_TEMP);
        try
        {
            inputStream >> reading;
            if (inputStream.eof() && ((reading.hour == INVALID_HOUR) || (reading.temp == INVALID_TEMP)))
            {
                break;
            }
            //cout << reading << endl;
        }
        catch (const runtime_error& e)
        {
            cout << e.what() << endl;
            return false;
        }

        readings.push_back(reading);
    }

    return true;
}

double CalculateTempMean(vector<Reading>& readings)
{
    double sum = 0;
    for (int cnt = 0; cnt < readings.size(); ++cnt)
    {
        sum += readings[cnt].temp;
    }

    return (sum / readings.size());
}

double CalculateTempMedian(vector<Reading>& readings)
{
    double median = 0;
    int mid = readings.size() / 2;

    median = readings[mid].temp;
    if (readings.size() % 2 == 0)
    {
        median += readings[mid - 1].temp;
        median /= 2;
    }

    return median;
}

int main()
{
    vector<Reading> readings;
    ifstream inputFile(RAW_TEMPS_FILENAME);
    if (!inputFile.good())
    {
        cout << "Couldn't open file: " << RAW_TEMPS_FILENAME << endl;
    }

    bool result = ReadInput(readings, inputFile);
    if (!result)
    {
        return 1;
    }

    cout << CalculateTempMean(readings) << endl;
    cout << CalculateTempMedian(readings) << endl;
    return 0;
}

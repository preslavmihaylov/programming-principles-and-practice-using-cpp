#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <stdexcept>
#include <cmath>

using namespace std;

#define RAW_TEMPS_FILENAME ("raw_temps.txt")
#define GENERATE_TEMPS_CNT (50)
#define TEMP_DIVISOR (1000)

struct Reading
{
    int hour; // [0-23]
    double temp;

    Reading()
        : hour(0), temp(0) {};
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

int generateHour()
{
    return (rand() % 24);
}

double generateTemperature()
{
    return (rand() % TEMP_DIVISOR) / 10.0;
}

char generateMeasure()
{
    int chance = (rand() % 2);
    if (chance == 0)
    {
        return 'c';
    }
    else
    {
        return 'f';
    }
}

int main()
{
    srand(time(NULL));
    ofstream outputFile(RAW_TEMPS_FILENAME);
    if (!outputFile.good())
    {
        cout << "Couldn't open file: " << RAW_TEMPS_FILENAME << endl;
    }

    for (int cnt = 0; cnt < GENERATE_TEMPS_CNT; ++cnt)
    {
        Reading reading;
        reading.hour = generateHour();
        reading.temp = generateTemperature();
        char measure = generateMeasure(); // In celsius
        if (measure == 'f')
        {
            reading.temp = (reading.temp * 1.8) + 32;
        }
        outputFile << reading << measure << endl;
    }
    return 0;
}

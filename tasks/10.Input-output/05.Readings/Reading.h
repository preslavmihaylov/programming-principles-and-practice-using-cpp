#ifndef READING_H
#define READING_H

#include <istream>
#include <ostream>

class Reading
{
public:
    int GetDay() const { return this->day; };
    int GetHour() const { return this->hour; };
    double GetTemperature() const { return this->temperature; };

    Reading(int day, int hour, double temperature);
    Reading() {};

    friend std::istream& operator>>(std::istream& inputStream, Reading& reading);
    friend std::ostream& operator<<(std::ostream& outputStream, const Reading& reading);
private:
    int day;
    int hour;
    double temperature;
};

#endif // READING_H

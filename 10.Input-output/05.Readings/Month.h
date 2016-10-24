#ifndef MONTH_H
#define MONTH_H

#include "Reading.h"

#include <string>
#include <istream>
#include <ostream>
#include <vector>

class Month
{
public:
    Month()
        : monthIndex(0) {};
    Month(std::string monthId);

    friend std::istream& operator>>(std::istream& inputStream, Month& month);
    friend std::ostream& operator<<(std::ostream& outputStream, const Month& month);

    int GetMonthIndex() const { return this->monthIndex; };
private:
    int monthIndex;
    std::vector<Reading> readings;
    bool IsDuplicateReading(const Reading& reading);
};

#endif // MONTH_H

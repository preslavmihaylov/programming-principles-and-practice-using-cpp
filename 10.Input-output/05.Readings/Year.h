#ifndef YEAR_H
#define YEAR_H

#include "Month.h"

#include <vector>
#include <istream>
#include <ostream>

class Year
{
public:
    Year()
        : yearOfData(1970) {};
    Year(int yearOfData);

    friend std::istream& operator>>(std::istream& inputStream, Year& year);
    friend std::ostream& operator<<(std::ostream& outputStream, const Year& year);
private:
    int yearOfData;
    std::vector<Month> months;
    bool IsDuplicateMonth(const Month& month);
};

#endif // YEAR_H

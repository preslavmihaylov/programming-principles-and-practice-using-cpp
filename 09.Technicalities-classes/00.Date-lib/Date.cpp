#include "Date.h"

#define MIN_YEAR (1800)
#define MAX_YEAR (2200)

using namespace Chrono;

Date& default_date()
{
    static Date defaultDate(2001, Date::jan, 1);
    return defaultDate;
}

bool Chrono::is_date(int y, Date::Month m, int d)
{
    bool isYearCorrect = false;
    bool isMonthCorrect = false;
    bool isDayCorrect = false;
    int maxDays = 0;

    if (y >= MIN_YEAR && y <= MAX_YEAR)
    {
        isYearCorrect = true;
    }

    switch (m)
    {
    case Date::feb:
        maxDays = is_leapyear(y) ? 29 : 28;
        isMonthCorrect = true;
        break;
    case Date::jan:
    case Date::mar:
    case Date::may:
    case Date::jul:
    case Date::aug:
    case Date::oct:
    case Date::dec:
        maxDays = 31;
        isMonthCorrect = true;
        break;
    case Date::apr:
    case Date::jun:
    case Date::sep:
    case Date::nov:
        maxDays = 30;
        isMonthCorrect = true;
        break;
    default:
        // False anyways --> left for completeness
        isMonthCorrect = false;
        break;
    }

    if (d >= 0 && d <= maxDays)
    {
        isDayCorrect = true;
    }

    return isDayCorrect && isMonthCorrect && isYearCorrect;
}

bool Chrono::is_leapyear(int y)
{
    bool isLeap = false;

    // If divisible by 100 -> should be divisible by 400 as well
    if (y % 100 == 0)
    {
        if (y % 400 == 0)
        {
            isLeap = true;
        }
    }
    else if (y % 4 == 0)
    {
        isLeap = true;
    }

    return isLeap;
}

bool Chrono::operator==(const Date& a, const Date& b)
{
    return (a.day() == b.day() &&
            a.month() == b.month() &&
            a.year() == b.year());
}

bool Chrono::operator!=(const Date& a, const Date& b)
{
    return !(a == b);
}

std::ostream& Chrono::operator<<(std::ostream& os, const Date& d)
{
    return
        os << '(' << d.day() << ", " << d.month() << ", " << d.year() << ')';
}

std::istream& Chrono::operator>>(std::istream& is, Date& date)
{
    char paran1, semicolon1, semicolon2, paran2;
    int y, m, d;

    is >> paran1 >> y >> semicolon1 >> m >> semicolon2 >> d >> paran2;

    if (!is)
    {
        return is;
    }

    if (paran1 != '(' ||
        semicolon1 != ',' ||
        semicolon2 != ',' ||
        paran2 != ')')
    {
        is.clear(std::ios_base::failbit);
        return is;
    }

    return is;
}

Date::Date(int y, Month m, int d)
{
    if (is_date(y, m, d))
    {
        this->y = y;
        this->m = m;
        this->d = d;
    }
    else
    {
        throw Invalid();
    }
}

Date::Date()
    : y(default_date().year()), m(default_date().month()), d(default_date().day())
{
};

void Date::add_day(int n)
{
    throw Invalid();
}

void Date::add_month(int n)
{
    throw Invalid();
}

void Date::add_year(int n)
{
    throw Invalid();
}

enum Day
{
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday
};

Day day_of_week(const Date& date)
{
    throw Date::Invalid();
}

Date next_Sunday(const Date& date)
{
    throw Date::Invalid();
}

Date next_weekday(const Date& date)
{
    throw Date::Invalid();
}

#include "Date.h"

#define MIN_YEAR (1800)
#define MAX_YEAR (2200)
#define MONTHS_COUNT (12)

using namespace Chrono;

static const int DAYS_IN_MONTH[MONTHS_COUNT + 1] =
{
    0, // Left for comfort
    31,
    28,
    31,
    30,
    31,
    30,
    31,
    31,
    30,
    31,
    30,
    31,
};

Date& default_date()
{
    static Date defaultDate(2001, Date::jan, 1);
    return defaultDate;
}

int GetDaysInMonth(int m, int y)
{
    int daysInMonth = DAYS_IN_MONTH[m];
    if (((Date::Month)m) == Date::feb && is_leapyear(y))
    {
        ++daysInMonth;
    }

    return daysInMonth;
}

bool Chrono::is_date(int y, Date::Month m, int d)
{
    bool isYearCorrect = false;
    bool isMonthCorrect = false;
    bool isDayCorrect = false;
    int daysInMonth = GetDaysInMonth(m, y);

    if (y >= MIN_YEAR && y <= MAX_YEAR)
    {
        isYearCorrect = true;
    }

    if (is_leapyear(y))
    {
        ++daysInMonth;
    }

    switch (m)
    {
    case Date::feb:
    case Date::jan:
    case Date::mar:
    case Date::may:
    case Date::jul:
    case Date::aug:
    case Date::oct:
    case Date::dec:
    case Date::apr:
    case Date::jun:
    case Date::sep:
    case Date::nov:
        isMonthCorrect = true;
        break;
    default:
        // False anyways --> left for completeness
        isMonthCorrect = false;
        break;
    }

    if (d >= 0 && d < daysInMonth)
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

std::istream& operator>>(std::istream& is, Chrono::Date& date)
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

    if (is_date(y, (Date::Month)m, d))
    {
        date.y = y;
        date.m = (Date::Month)m;
        date.d = d - 1;
    }

    return is;
}

Date::Date(int y, Month m, int d)
{
    if (is_date(y, m, d))
    {
        this->y = y;
        this->m = m;
        this->d = d - 1;
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
    int daysInMonth = GetDaysInMonth(this->m, this->y);

    while (n >= (daysInMonth - this->d))
    {
        n -= (daysInMonth - this->d);
        this->add_month(1);
        daysInMonth = GetDaysInMonth(this->m, this->y);
        this->d = 0;
    }

    this->d += n;
}

void Date::add_month(int n)
{
    int month = (int)((this->m - 1) + n);
    int yearsToAdd = month / MONTHS_COUNT;
    this->m = (Date::Month)((month % MONTHS_COUNT) + 1);
    this->add_year(yearsToAdd);
}

void Date::add_year(int n)
{
    this->y += n;
}

int Chrono::day_of_week(const Date& date)
{
    int y = date.year();
    int m = date.month();
    int d = date.day();

    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + d) % 7;
}

Date Chrono::next_Sunday(const Date& date)
{
    int dayOfWeek = day_of_week(date);
    Date newDate(date.year(), date.month(), date.day());
    int daysToNextSunday = 7 - dayOfWeek;
    newDate.add_day(daysToNextSunday);

    return newDate;
}

Date Chrono::next_weekday(const Date& date)
{
    Date newDate(date.year(), date.month(), date.day());
    int dayOfWeek = day_of_week(date);
    if (dayOfWeek == 7)
    {
        newDate.add_day(2);
    }
    else
    {
        newDate.add_day(1);
    }

    return newDate;
}

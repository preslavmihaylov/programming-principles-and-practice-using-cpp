#ifndef DATE_H
#define DATE_H

#include <ostream>
#include <istream>

namespace Chrono
{
    class Date
    {
    public:
        enum Month
        {
            jan=1,
            feb,
            mar,
            apr,
            may,
            jun,
            jul,
            aug,
            sep,
            oct,
            nov,
            dec
        };

        class Invalid {};

        Date (int y, Month m, int d);
        Date();

        // non-modifying operations
        int day() const { return d; }
        Month month() const { return m; }
        int year() const { return y; }

        // modifying operations
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);
    private:
       int y;
       Month m;
       int d;
    };

    bool is_date(int y, Date::Month m, int d);

    bool is_leapyear(int y);

    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);

    std::ostream& operator<<(std::ostream& os, const Date& d);
    std::istream& operator>>(std::istream& is, Date& d);
} // Chrono


#endif // DATE_H

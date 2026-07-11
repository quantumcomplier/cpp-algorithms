#include "Date.h"
#include <iomanip>

std::ostream& operator<<(std::ostream& output, const Date& d)
{
    output << std::setw(2) << std::setfill('0') << d.month << "/"
        << std::setw(2) << std::setfill('0') << d.day << "/"
        << d.year;
    return output;
}

Date::Date()
{
    setDate(1, 1, 1900);
}

Date::Date(int m, int d, int yyyy)
{
    setDate(m, d, yyyy);
}

Date::~Date() {}

void Date::setDate(int m, int d, int yyyy)
{
    month = m;
    day = d;
    year = yyyy;
}

#pragma once
#include <iostream>
#include <cstdlib>
#include <cctype>

// Date class provides basic storage and formatted output for month/day/year
class Date
{
    // overload of << operator to allow formatted date output
    friend std::ostream& operator<<(std::ostream& output, const Date& d);

private:
    int month; // holds month value
    int day;   // holds day value
    int year;  // holds year value

public:
    Date(); // zero-argument constructor sets default date
    Date(int m, int d, int yyyy); // constructor sets date using parameters
    ~Date(); // destructor 

    void setDate(int m, int d, int yyyy); // sets month, day, and year
};

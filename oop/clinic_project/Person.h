#pragma once
#include <string>
#include "Date.h"

// Person class stores basic identity and location information
class Person
{
private:
    std::string _firstName; // holds first name
    std::string _lastName;  // holds last name
    std::string _city;      // holds city name
    std::string _state;     // holds state name
    Date _birthDate;        // holds birth date

public:
    Person(); // zero-argument constructor to initialize members
    Person(std::string first, std::string last, std::string city, std::string state, Date birth); // constructor sets all members
    ~Person(); // destructor

    void setFirstName(std::string first); // sets first name
    void setLastName(std::string last);   // sets last name
    void setCity(std::string city);       // sets city name
    void setState(std::string state);     // sets state name
    void setBirthDate(Date birth);        // sets birth date

    std::string getFirstName() const; // returns first name
    std::string getLastName() const;  // returns last name
    std::string getCity() const;      // returns city name
    std::string getState() const;     // returns state name
    Date getBirthDate() const;        // returns birth date

    std::string createFullName() const; // returns "Last, First"
};

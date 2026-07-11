#include "Person.h"

// zero-argument constructor initializes members
Person::Person()
{
    _firstName = "";
    _lastName = "";
    _city = "";
    _state = "";
    _birthDate.setDate(1, 1, 1900);
}

// constructor sets all members using provided parameters
Person::Person(std::string first, std::string last, std::string city, std::string state, Date birth)
{
    setFirstName(first);
    setLastName(last);
    setCity(city);
    setState(state);
    setBirthDate(birth);
}

// destructor
Person::~Person() {}

// setters
void Person::setFirstName(std::string first)
{
    _firstName = first;
}

void Person::setLastName(std::string last)
{
    _lastName = last;
}

void Person::setCity(std::string city)
{
    _city = city;
}

void Person::setState(std::string state)
{
    _state = state;
}

void Person::setBirthDate(Date birth)
{
    _birthDate = birth;
}

// getters
std::string Person::getFirstName() const
{
    return _firstName;
}

std::string Person::getLastName() const
{
    return _lastName;
}

std::string Person::getCity() const
{
    return _city;
}

std::string Person::getState() const
{
    return _state;
}

Date Person::getBirthDate() const
{
    return _birthDate;
}

// returns "last, first" (ASCII only — no UTF‑8 dash)
std::string Person::createFullName() const
{
    return _lastName + ", " + _firstName;
}

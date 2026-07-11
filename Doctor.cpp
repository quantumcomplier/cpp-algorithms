#include "Doctor.h"

// zero-argument constructor initializes members
Doctor::Doctor() : Person()
{
    _title = "";
    _valueCompensationPackage = 0.0;
    _ownershipEstablished.setDate(1, 1, 1900);
}

// constructor sets all members using parameters
Doctor::Doctor(std::string first, std::string last, std::string city, std::string state,
    Date birth, std::string title, double compensation, Date ownership)
    : Person(first, last, city, state, birth)
{
    setTitle(title);
    setValueCompensationPackage(compensation);
    setOwnershipEstablished(ownership);
}

// destructor
Doctor::~Doctor() {}

// sets doctor title
void Doctor::setTitle(std::string title)
{
    _title = title;
}

// sets compensation package value
void Doctor::setValueCompensationPackage(double value)
{
    _valueCompensationPackage = value;
}

// sets ownership date
void Doctor::setOwnershipEstablished(Date ownership)
{
    _ownershipEstablished = ownership;
}

// returns doctor title
std::string Doctor::getTitle() const
{
    return _title;
}

// returns compensation package value
double Doctor::getValueCompensationPackage() const
{
    return _valueCompensationPackage;
}

// returns ownership date
Date Doctor::getOwnershipEstablished() const
{
    return _ownershipEstablished;
}

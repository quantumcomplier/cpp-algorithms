#include "Nurse.h"

// zero-argument constructor initializes to default values
Nurse::Nurse() : Person()
{
    _specialty = "";
    _salary = 0.0;
    _position = "";
    _dateHired.setDate(1, 1, 1900);
}

// constructor sets all members using provided parameters
Nurse::Nurse(std::string first, std::string last, std::string city, std::string state,
    Date birth, std::string specialty, double salary, std::string position, Date hired)
    : Person(first, last, city, state, birth)
{
    setSpecialty(specialty);
    setSalary(salary);
    setPosition(position);
    setDateHired(hired);
}

// destructor
Nurse::~Nurse() {}

// sets nurse specialty
void Nurse::setSpecialty(std::string specialty)
{
    _specialty = specialty;
}

// sets nurse salary
void Nurse::setSalary(double salary)
{
    _salary = salary;
}

// sets nurse position
void Nurse::setPosition(std::string position)
{
    _position = position;
}

// sets hire date
void Nurse::setDateHired(Date hired)
{
    _dateHired = hired;
}

// returns nurse specialty
std::string Nurse::getSpecialty() const
{
    return _specialty;
}

// returns nurse salary
double Nurse::getSalary() const
{
    return _salary;
}

// returns nurse position
std::string Nurse::getPosition() const
{
    return _position;
}

// returns hire date
Date Nurse::getDateHired() const
{
    return _dateHired;
}

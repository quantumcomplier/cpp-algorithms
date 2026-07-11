#include "Clinic.h"
#include <algorithm>

// zero-argument constructor initializes to default values
Clinic::Clinic()
{
    _name = "";
    _city = "";
    _state = "";
    _openedForBusiness.setDate(1, 1, 1900);
}

// constructor sets all members
Clinic::Clinic(std::string name, Doctor doctor, Date opened, std::string city, std::string state)
{
    setName(name);
    setDoctor(doctor);
    setOpenedForBusiness(opened);
    setCity(city);
    setState(state);
}

// destructor 
Clinic::~Clinic() {}

// setters
void Clinic::setName(std::string name) { _name = name; }
void Clinic::setDoctor(Doctor doctor) { _doctor = doctor; }
void Clinic::setOpenedForBusiness(Date opened) { _openedForBusiness = opened; }
void Clinic::setCity(std::string city) { _city = city; }
void Clinic::setState(std::string state) { _state = state; }

// getters
std::string Clinic::getName() const { return _name; }
Doctor Clinic::getDoctor() const { return _doctor; }
Date Clinic::getOpenedForBusiness() const { return _openedForBusiness; }
std::string Clinic::getCity() const { return _city; }
std::string Clinic::getState() const { return _state; }

// nurse handling
void Clinic::addNurse(Nurse nurse)
{
    _nurses.push_back(nurse);
}

int Clinic::numberNurses() const
{
    return static_cast<int>(_nurses.size());
}

void Clinic::sortNurses()
{
    std::sort(_nurses.begin(), _nurses.end(),
        [](const Nurse& a, const Nurse& b)
        {
            return a.getLastName() < b.getLastName();
        });
}

std::vector<Nurse> Clinic::getNurses() const
{
    return _nurses;
}

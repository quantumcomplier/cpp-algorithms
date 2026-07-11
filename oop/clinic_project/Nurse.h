#pragma once
#include <string>
#include "Person.h"

// Nurse class stores nurse information and inherits Person
class Nurse : public Person
{
private:
    std::string _specialty; // holds nurse specialty
    double _salary; // holds nurse salary value
    std::string _position; // holds nurse position
    Date _dateHired; // holds date nurse was hired

public:
    Nurse(); // zero-argument constructor initializes members
    Nurse(std::string first, std::string last, std::string city, std::string state,
        Date birth, std::string specialty, double salary, std::string position, Date hired); // constructor sets all members
    ~Nurse(); // destructor

    void setSpecialty(std::string specialty); // sets nurse specialty
    void setSalary(double salary); // sets nurse salary
    void setPosition(std::string position); // sets nurse position
    void setDateHired(Date hired); // sets hire date

    std::string getSpecialty() const; // returns nurse specialty
    double getSalary() const; // returns nurse salary
    std::string getPosition() const; // returns nurse position
    Date getDateHired() const; // returns hire date
};

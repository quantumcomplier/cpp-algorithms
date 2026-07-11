#pragma once
#include <string>
#include <vector>
#include "Doctor.h"
#include "Nurse.h"
#include "Date.h"

// Clinic class stores clinic information and contains doctor and nurse objects
class Clinic
{
private:
    std::string _name; // holds clinic name
    Doctor _doctor; // holds doctor object
    Date _openedForBusiness; // holds date clinic opened
    std::string _city; // holds clinic city
    std::string _state; // holds clinic state
    std::vector<Nurse> _nurses; // holds list of nurse objects

public:
    Clinic(); // zero-argument constructor initializes members
    Clinic(std::string name, Doctor doctor, Date opened, std::string city, std::string state); // constructor
    ~Clinic(); // destructor

    void setName(std::string name); // sets clinic name
    void setDoctor(Doctor doctor); // sets doctor object
    void setOpenedForBusiness(Date opened); // sets opening date
    void setCity(std::string city); // sets clinic city
    void setState(std::string state); // sets clinic state

    std::string getName() const; // returns clinic name
    Doctor getDoctor() const; // returns doctor object
    Date getOpenedForBusiness() const; // returns opening date
    std::string getCity() const; // returns clinic city
    std::string getState() const; // returns clinic state

    void addNurse(Nurse nurse); // adds nurse to vector
    int numberNurses() const; // returns number of nurses
    void sortNurses(); // sorts nurses by last name
    void displayClinicInfo() const; // displays full clinic report

    std::vector<Nurse> getNurses() const; // returns list of nurses

};

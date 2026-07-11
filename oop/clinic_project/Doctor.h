#pragma once
#include <string>
#include "Person.h"

// Doctor class (inherits Person class) stores doctor information
class Doctor : public Person
{
private:
    std::string _title; // holds doctor title
    double _valueCompensationPackage; // holds compensation package value
    Date _ownershipEstablished; // holds date doctor took ownership

public:
    Doctor(); // zero-argument constructor 
    Doctor(std::string first, std::string last, std::string city, std::string state,
        Date birth, std::string title, double compensation, Date ownership); // constructor with arguments
    ~Doctor(); // destructor

    void setTitle(std::string title); // set doctor title
    void setValueCompensationPackage(double value); // set compensation package value
    void setOwnershipEstablished(Date ownership); // set ownership date

    std::string getTitle() const; // return doctor title
    double getValueCompensationPackage() const; // return compensation package value
    Date getOwnershipEstablished() const; // return ownership date
};

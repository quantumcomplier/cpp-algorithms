#pragma once
#include <string>
#include <iostream>

// Base class for all pets.
// Derived classes (Dog, Cat, Bird, Fish, Hamster) will come from this.
class Pet
{
protected:
    // Stores the pet's name; must not be blank.
    std::string _name;

    // Holds the 4-digit birth year for the pet.
    int _birthYear{};

    // Indicates the type of pet (Dog, Cat, etc.); set only by derived classes.
    std::string _typeOf;

    // Weight of the pet; generated randomly based on pet type.
    int _weight{};

    // Setter for the pet type; only base and derived classes can use this.
    void setTypeOf(const std::string& t) { _typeOf = t; }

public:
    // Constant used for age calculation.
    static const int CURRENT_YEAR = 2026;

    // Default constructor — prints required message.
    Pet();

    // Builds a Pet using provided name, birth year, and weight.
    Pet(const std::string& nm, int by, int wt);

    // Virtual destructor so derived class destructors run correctly.
    virtual ~Pet();

    // Setter for name 
    void setName(const std::string& nm) { _name = nm; }

    // Setter for birth year.
    void setBirthYear(int by) { _birthYear = by; }

    // Setter for weight.
    void setWeight(int wt) { _weight = wt; }

    // Getter for name.
    std::string getName() const { return _name; }

    // Getter for birth year.
    int getBirthYear() const { return _birthYear; }

    // Getter for weight.
    int getWeight() const { return _weight; }

    // Getter for pet type.
    std::string getTypeOf() const { return _typeOf; }

    // Calculates age using CURRENT_YEAR minus birth year.
    double calcAge() const;

    // Virtual function that derived classes will override
    // to display their pet info.
    virtual void displayPetInfo();
};

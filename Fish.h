#pragma once
#include "Pet.h"

// Fish class derived from Pet.

class Fish : public Pet
{
public:
    // Basic Fish constructor.
    Fish();

    // Builds a Fish using name, birth year, and weight.
    Fish(const std::string& nm, int by, int wt);

    // Fish destructor.
    ~Fish();

    // Shows Fish info in the report.
    void displayPetInfo() override;
};

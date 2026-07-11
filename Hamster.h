#pragma once
#include "Pet.h"

// Hamster class derived from Pet.
class Hamster : public Pet
{
public:
    // Default constructor — sets type and prints message.
    Hamster();

    // Builds a Hamster using the provided values.
    Hamster(const std::string& nm, int by, int wt);

    // Destructor — prints Hamster-specific message.
    ~Hamster();

    // Displays Hamster details in the final report.
    void displayPetInfo() override;
};

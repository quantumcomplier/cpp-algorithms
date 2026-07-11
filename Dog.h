#pragma once
#pragma once
#include "Pet.h"

// Dog class derived from Pet.
// Has Dog-specific constructor messages
// and its own version of displayPetInfo().
class Dog : public Pet
{
public:
    // Default Dog constructor; prints required message.
    Dog();

    // Builds a Dog using name, birth year, and weight.
    // Passes values to the Pet constructor.
    Dog(const std::string& nm, int by, int wt);

    // Destructor prints Dog-specific message
    ~Dog();

    // Shows formatted Dog info
    void displayPetInfo() override;
};

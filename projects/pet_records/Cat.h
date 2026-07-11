#pragma once
#pragma once
#include "Pet.h"

// Cat class derived from Pet.
// Nothing extra is stored here — just Cat-specific behavior
// and the required constructor/destructor messages.
class Cat : public Pet
{
public:
    // Basic constructor for a Cat; prints the expected message.
    Cat();

    // Builds a Cat using the provided values.
    // Passes everything up to the Pet constructor.
    Cat(const std::string& nm, int by, int wt);

    // Destructor — Cat-specific message printed here.
    ~Cat();

    // Shows the Cat's details in the formatted report.
    // Overrides the virtual function from Pet.
    void displayPetInfo() override;
};

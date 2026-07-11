#include "Pet.h"

// Default constructor — required message printed.
Pet::Pet()
{
    std::cout << "Invoking Pet default constructor\n";
}

// 3‑argument constructor — uses setters and prints required message.
Pet::Pet(const std::string& nm, int by, int wt)
{
    std::cout << "Invoking Pet 3-argument constructor\n";
    setName(nm);
    setBirthYear(by);
    setWeight(wt);
}

// Virtual destructor — ensures derived destructors run too.
Pet::~Pet()
{
    std::cout << "Invoking Pet destructor\n";
}

// Calculates the pet's age based on CURRENT_YEAR.
double Pet::calcAge() const
{
    return static_cast<double>(CURRENT_YEAR - _birthYear);
}

// Base version of displayPetInfo
void Pet::displayPetInfo()
{
    std::cout << "[Pet Base] displayPetInfo() called (should be overridden)\n";
}

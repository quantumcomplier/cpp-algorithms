#include "Hamster.h"

// Default Hamster constructor.
// Identifies this object as a Hamster 
Hamster::Hamster()
{
    std::cout << "Invoking Hamster default constructor\n";
    setTypeOf("Hamster");
}

// 3‑argument Hamster constructor.
Hamster::Hamster(const std::string& nm, int by, int wt)
    : Pet(nm, by, wt)
{
    std::cout << "Invoking Hamster 3-argument constructor\n";
    setTypeOf("Hamster");
}

// Destructor — prints Hamster-specific message.
Hamster::~Hamster()
{
    std::cout << "Invoking Hamster destructor\n";
}

// Displays Hamster information.
// Same general layout as the other pets.
void Hamster::displayPetInfo()
{
    std::cout << "\n--- Pet Information ---\n";
    std::cout << "Type: " << getTypeOf() << "\n";
    std::cout << "Name: " << getName() << "\n";
    std::cout << "Birth Year: " << getBirthYear() << "\n";
    std::cout << "Weight: " << getWeight() << " lbs\n";
    std::cout << "Age: " << calcAge() << " years\n";
}

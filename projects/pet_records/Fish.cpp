#include "Fish.h"

// Default Fish constructor.
// Marks this pet as a Fish and prints the required message.
Fish::Fish()
{
    std::cout << "Invoking Fish default constructor\n";
    setTypeOf("Fish");
}

// 3‑argument Fish constructor.
// Passes shared values to Pet, then sets type.
Fish::Fish(const std::string& nm, int by, int wt)
    : Pet(nm, by, wt)
{
    std::cout << "Invoking Fish 3-argument constructor\n";
    setTypeOf("Fish");
}

// Destructor 
Fish::~Fish()
{
    std::cout << "Invoking Fish destructor\n";
}

// Displays Fish information.
// Keeps formatting consistent with other pets.
void Fish::displayPetInfo()
{
    std::cout << "\n--- Pet Information ---\n";
    std::cout << "Type: " << getTypeOf() << "\n";
    std::cout << "Name: " << getName() << "\n";
    std::cout << "Birth Year: " << getBirthYear() << "\n";
    std::cout << "Weight: " << getWeight() << " lbs\n";
    std::cout << "Age: " << calcAge() << " years\n";
}

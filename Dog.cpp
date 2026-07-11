#include "Dog.h"

// Default constructor — sets type and prints required message.
Dog::Dog()
{
    std::cout << "Invoking Dog default constructor\n";
    setTypeOf("Dog");
}

// 3‑argument constructor — forwards values to Pet constructor,
// then sets the type and prints message.
Dog::Dog(const std::string& nm, int by, int wt)
    : Pet(nm, by, wt)
{
    std::cout << "Invoking Dog 3-argument constructor\n";
    setTypeOf("Dog");
}

// Destructor — prints required message.
Dog::~Dog()
{
    std::cout << "Invoking Dog destructor\n";
}

// Displays formatted Dog information.
void Dog::displayPetInfo()
{
    std::cout << "\n--- Pet Information ---\n";
    std::cout << "Type: " << getTypeOf() << "\n";
    std::cout << "Name: " << getName() << "\n";
    std::cout << "Birth Year: " << getBirthYear() << "\n";
    std::cout << "Weight: " << getWeight() << " lbs\n";
    std::cout << "Age: " << calcAge() << " years\n";
}

#include "Cat.h"

// Default Cat constructor.
// Sets the type and announces itself.
Cat::Cat()
{
    std::cout << "Invoking Cat default constructor\n";
    setTypeOf("Cat");
}

// 3‑argument Cat constructor.
// Uses the Pet constructor for the shared fields,
// then tags this object as a Cat.
Cat::Cat(const std::string& nm, int by, int wt)
    : Pet(nm, by, wt)
{
    std::cout << "Invoking Cat 3-argument constructor\n";
    setTypeOf("Cat");
}

// Destructor — required message printed.
Cat::~Cat()
{
    std::cout << "Invoking Cat destructor\n";
}

// Displays Cat information.
// Uses getters so the formatting stays consistent across all pets.
void Cat::displayPetInfo()
{
    std::cout << "\n--- Pet Information ---\n";
    std::cout << "Type: " << getTypeOf() << "\n";
    std::cout << "Name: " << getName() << "\n";
    std::cout << "Birth Year: " << getBirthYear() << "\n";
    std::cout << "Weight: " << getWeight() << " lbs\n";
    std::cout << "Age: " << calcAge() << " years\n";
}

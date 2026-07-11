#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

#include "Dog.h"
#include "Cat.h"
#include "Bird.h"
#include "Fish.h"
#include "Hamster.h"

// Sources used:
// https://cplusplus.com/reference/
// https://en.cppreference.com/w/cpp/language/virtual
// Code snippet patterns from Professor Walter Williams

// Function headers
void cinClear();
int getMenuSelection();
int getInt(int min, int max);
std::string getName();
int getRandomNumber(int minValue, int maxValue);
void pressEnterToContinue();

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    bool petsPicked[5]{ false, false, false, false, false };
    Pet* selectedPets[3]{ nullptr, nullptr, nullptr };

    int slot = 0;

    while (slot < 3)
    {
        // Menu screen (spacing matches screenshot exactly)
        std::cout << "David Briceno - Assignment 8 - Polymorphism\n\n";
        std::cout << "Pet Adoption Menu\n";
        std::cout << "Pick 3 different pets\n\n";
        std::cout << "1 - Dog\n";
        std::cout << "2 - Cat\n";
        std::cout << "3 - Bird\n";
        std::cout << "4 - Fish\n";
        std::cout << "5 - Hamster\n\n";
        std::cout << "Selection: ";

        int choice = getMenuSelection();

        // Duplicate pet check
        if (petsPicked[choice - 1])
        {
            std::string typeName;
            switch (choice)
            {
            case 1: typeName = "Dog"; break;
            case 2: typeName = "Cat"; break;
            case 3: typeName = "Bird"; break;
            case 4: typeName = "Fish"; break;
            case 5: typeName = "Hamster"; break;
            }

            // EXACT formatting from screenshot
            std::cout << "The " << typeName << " has already been selected.\n";
            std::cout << "Try again.\n\n";
            pressEnterToContinue();
            continue;
        }

        petsPicked[choice - 1] = true;

        // Determine pet type and birth year range
        std::string petType;
        int minYear = 0, maxYear = 0;

        switch (choice)
        {
        case 1: petType = "Dog";     minYear = 2015; maxYear = 2026; break;
        case 2: petType = "Cat";     minYear = 2012; maxYear = 2026; break;
        case 3: petType = "Bird";    minYear = 2020; maxYear = 2026; break;
        case 4: petType = "Fish";    minYear = 2022; maxYear = 2026; break;
        case 5: petType = "Hamster"; minYear = 2023; maxYear = 2026; break;
        }

        // Pet Entry screen 
        std::cout << petType << " Entry\n\n";

        std::cout << "Name: ";
        std::string name = getName();

        std::cout << "Birth Year (" << minYear << "-" << maxYear << "): ";
        int birthYear = getInt(minYear, maxYear);

        std::cout << "\n";

        // Weight generation
        int weight = 0;
        switch (choice)
        {
        case 1: weight = getRandomNumber(5, 100); break;
        case 2: weight = getRandomNumber(5, 10); break;
        case 3: weight = getRandomNumber(1, 5); break;
        case 4: weight = getRandomNumber(0, 1); break;
        case 5: weight = getRandomNumber(1, 2); break;
        }

        // Create correct pet object
        switch (choice)
        {
        case 1: selectedPets[slot] = new Dog(name, birthYear, weight); break;
        case 2: selectedPets[slot] = new Cat(name, birthYear, weight); break;
        case 3: selectedPets[slot] = new Bird(name, birthYear, weight); break;
        case 4: selectedPets[slot] = new Fish(name, birthYear, weight); break;
        case 5: selectedPets[slot] = new Hamster(name, birthYear, weight); break;
        }

        std::cout << "\n";
        pressEnterToContinue();
        slot++;
    }

    // Final report header
    std::cout << "You have selected the following pets:\n\n";

    // Display each pet
    for (int i = 0; i < 3; i++)
    {
        std::cout << "    My name is " << selectedPets[i]->getName()
            << ", and I am a " << selectedPets[i]->getTypeOf() << ".\n";
        std::cout << "My properties are:\n";
        std::cout << "    Weight: " << selectedPets[i]->getWeight() << "\n";
        std::cout << "    Birth Year: " << selectedPets[i]->getBirthYear() << "\n";
        std::cout << "    Age: " << selectedPets[i]->calcAge() << "\n\n\n";
    }

    // Destructor
    for (int i = 0; i < 3; i++)
    {
        delete selectedPets[i];
    }

    pressEnterToContinue();
    return 0;
}

// Clears input buffer
void cinClear()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Validates menu selection (1-5) with error message
int getMenuSelection()
{
    int value;

    while (true)
    {
        if (!(std::cin >> value))
        {
            std::cout << "Invalid entry. Please enter a number from 1 to 5.\n";
            cinClear();
            continue;
        }

        if (value < 1 || value > 5)
        {
            std::cout << "Invalid selection. Choose a number between 1 and 5.\n";
            cinClear();
            continue;
        }

        cinClear();
        return value;
    }
}

// Validates integer input and range
int getInt(int min, int max)
{
    int value;

    while (true)
    {
        if (!(std::cin >> value))
        {
            std::cout << "Invalid value. A non-numeric character was entered.\n";
            cinClear();
            continue;
        }

        if (value < min || value > max)
        {
            std::cout << "Invalid value. The number must be between "
                << min << " and " << max << ".\n";
            cinClear();
            continue;
        }

        cinClear();
        return value;
    }
}

// Validates non-empty string input
std::string getName()
{
    std::string name;
    std::getline(std::cin, name);

    while (name.empty())
    {
        std::cout << "Invalid value. A blank entry was received.\n";
        std::getline(std::cin, name);
    }

    return name;
}

// Generates random number in range
int getRandomNumber(int minValue, int maxValue)
{
    int interval = maxValue - minValue + 1;
    return (rand() % interval) + minValue;
}

// Standard pause function
void pressEnterToContinue()
{
    std::cout << "Press ENTER to continue...";
    cinClear();
    std::cin.get();
}

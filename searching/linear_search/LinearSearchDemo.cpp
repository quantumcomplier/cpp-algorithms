// LinearSearchDemo.cpp : This program demonstrates liner searching in C++

#include <iostream>
#include <vector>
#include <iomanip>

// Linear search function
int linearSearch(const std::vector<int>& data, int target)
{
    for (int i = 0; i < static_cast<int>(data.size()); i++)
    {
        if (data[i] == target)
        {
            return i; // Found at index i
        }
    }
    return -1; // Not found
}

// Prints the vector contents
void printVector(const std::vector<int>& data)
{
    for (int value : data)
    {
        std::cout << std::setw(4) << value;
    }
    std::cout << "\n";
}

int main()
{
    std::vector<int> numbers{ 42, 17, 8, 99, 23, 4, 56, 12 };

    std::cout << "List of values:\n";
    printVector(numbers);

    int target;
    std::cout << "\nEnter a number to search for: ";
    std::cin >> target;

    int index = linearSearch(numbers, target);

    if (index != -1)
    {
        std::cout << "\nValue " << target << " found at index " << index << ".\n";
    }
    else
    {
        std::cout << "\nValue " << target << " not found in the list.\n";
    }

    std::cout << "\nDone.\n";
    return 0;
}

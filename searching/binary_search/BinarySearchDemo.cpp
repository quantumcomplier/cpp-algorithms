// BinarySearchDemo.cpp : This program demonstrates binary searching

#include <iostream>
#include <vector>
#include <iomanip>

// Binary search function
int binarySearch(const std::vector<int>& data, int target)
{
    int left = 0;
    int right = static_cast<int>(data.size()) - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (data[mid] == target)
        {
            return mid; // Found
        }
        else if (data[mid] < target)
        {
            left = mid + 1; // Search right half
        }
        else
        {
            right = mid - 1; // Search left half
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
    // Binary search requires a sorted list
    std::vector<int> numbers{ 4, 8, 12, 17, 23, 42, 56, 99 };

    std::cout << "Sorted list:\n";
    printVector(numbers);

    int target;
    std::cout << "\nEnter a number to search for: ";
    std::cin >> target;

    int index = binarySearch(numbers, target);

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

// InsertionSortDemo.cpp : A Program to demonstrate insertion sorting

#include <iostream>
#include <vector>
#include <iomanip>

// Insertion sort function
void insertionSort(std::vector<int>& data)
{
    int n = static_cast<int>(data.size());

    for (int i = 1; i < n; i++)
    {
        int key = data[i];
        int j = i - 1;

        // Shift elements to the right until the correct spot is found
        while (j >= 0 && data[j] > key)
        {
            data[j + 1] = data[j];
            j--;
        }

        data[j + 1] = key;
    }
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

    std::cout << "Original list:\n";
    printVector(numbers);

    insertionSort(numbers);

    std::cout << "\nSorted list (Insertion Sort):\n";
    printVector(numbers);

    std::cout << "\nDone.\n";
    return 0;
}

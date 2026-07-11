// SelectionSortDemo.cpp : A demonstration of selection sorting in C++

#include <iostream>
#include <vector>
#include <iomanip>

// Selection sort function
void selectionSort(std::vector<int>& data)
{
    int n = static_cast<int>(data.size());

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;

        // Find the smallest value in the remaining unsorted portion
        for (int j = i + 1; j < n; j++)
        {
            if (data[j] < data[minIndex])
            {
                minIndex = j;
            }
        }

        // Swap the smallest value into its correct position
        std::swap(data[i], data[minIndex]);
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

    selectionSort(numbers);

    std::cout << "\nSorted list (Selection Sort):\n";
    printVector(numbers);

    std::cout << "\nDone.\n";
    return 0;
}

// bubble_sort.cpp : Demonstration of bubble sorting
#include <iostream>
#include <vector>
#include <iomanip>

// Bubble sort function
void bubbleSort(std::vector<int>& data)
{
    bool swapped = true;
    int n = static_cast<int>(data.size());

    while (swapped)
    {
        swapped = false;

        for (int i = 0; i < n - 1; i++)
        {
            if (data[i] > data[i + 1])
            {
                std::swap(data[i], data[i + 1]);
                swapped = true;
            }
        }

        // After each pass, the largest element is at the end.
        // We can reduce the range for the next pass.
        n--;
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

    bubbleSort(numbers);

    std::cout << "\nSorted list (Bubble Sort):\n";
    printVector(numbers);

    std::cout << "\nDone.\n";
    return 0;
}

// Inventory Report -- Program to practice dynamic memory and pointers with Product objects.
//CSIS 112 B01 202630


//<Sources>
// Professor Walter Williams - provided some recommended code for this assignment.

//Include statements 
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstdlib>
#include "Product.h"

using namespace std;


//Global declarations: Constants and type definitions only -- no variables

//Function prototypes 
void PressEnterToContinue();
string GetNonBlankString(const string& prompt);
int GetIntInRange(const string& prompt, int minVal, int maxVal);
double GetDoubleInRange(const string& prompt, double minVal, double maxVal);


int main() 
{
    // Purpose of this assignment is to get hands-on practice using pointers (dynamic memory) to allocate and deallocate
    // dynamic objects by generating an inventory report.
    
    // Random seed  using srand(100) 
    srand(100);

    string companyName;
    int numProducts = 0;

 
    cout << "David Briceno - Lab 6\n\n";

   // User input for company name (validadted with function)
    companyName = GetNonBlankString("Name of the Electronics Shop: ");

  
    // NUMBER OF PRODUCTS INPUT
    // Must be between 2 and 5 inclusive.
    numProducts = GetIntInRange("Number of products to enter (2-5): ", 2, 5);
    cout << endl;

    PressEnterToContinue();

    
    // Create an array of pointers to Product objects.
    Product** inventory = new Product * [numProducts];

     // PRODUCT INPUT LOOP
    // For each product: 1. Create a new Product object, 2. Gather and validate user input, 3. Generate random quantity (5–10)
    //   4. Store object pointer in the array
    
    for (int i = 0; i < numProducts; ++i)
    {
        cout << "\nProduct #" << (i + 1) << "\n\n";

        Product* tempProduct = new Product;

        // Name (cannot be blank)
        string name = GetNonBlankString("Name (blank not allowed): ");

        // Category (cannot be blank)
        string category = GetNonBlankString("Category (blank not allowed): ");

        // Price (100.00 - 1000.00)
        double price = GetDoubleInRange("Price (100.00 - 1000.00): ", 100.00, 1000.00);

        // Random quantity (5–10)
        int quantity = (rand() % 6) + 5;

        // Load object using setters
        
        tempProduct->set_nameOfProduct(name);
        tempProduct->set_categoryOfProduct(category);
        tempProduct->set_priceOfProduct(price);
        tempProduct->set_quantityOnHand(quantity);

        // Store pointer in array
        inventory[i] = tempProduct;

        PressEnterToContinue();
    }

    
    // Inventory report header
    cout << "\n" << companyName << " -- Inventory Report\n\n";

    // Column headers to match formatting.
    
    cout << left << setw(24) << "Product Name"
        << left << setw(16) << "Category"
        << right << setw(10) << "Price"
        << right << setw(12) << "Quantity"
        << right << setw(16) << "Value On Hand"
        << endl;

    double totalValue = 0.0;

    
    // Output for each product:
    
    for (int i = 0; i < numProducts; ++i)
    {
        Product* p = inventory[i];
        double valueOnHand = p->calculateValue();
        totalValue += valueOnHand;

        cout << left << setw(24) << p->get_nameOfProduct()
            << left << setw(16) << p->get_categoryOfProduct()
            << right << setw(10) << fixed << setprecision(2) << p->get_priceOfProduct()
            << right << setw(12) << p->get_quantityOnHand()
            << right << setw(16) << fixed << setprecision(2) << valueOnHand
            << endl;
    }

    cout << endl;

  
    // Total value output
    cout << left << setw(24) << "TOTAL VALUE"
        << left << setw(16) << ""
        << right << setw(10) << ""
        << right << setw(12) << ""
        << right << setw(16) << fixed << setprecision(2) << totalValue
        << endl;

    PressEnterToContinue();

    
    // MEMORY CLEANUP
    // Source: Professor Walter Williams
    // Two-step deletion:
    //   1. Delete each object
    //   2. Delete the array of pointers
    
    for (int i = 0; i < numProducts; ++i)
    {
        delete inventory[i];
        inventory[i] = nullptr;
    }

    delete[] inventory;
    inventory = nullptr;
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////
//Function definitions


// Purpose- Pauses the program until the user presses ENTER.
// Source: Professor Williams

    void PressEnterToContinue()
    {
        cout << "\n\nPress ENTER to continue..." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }




// Purpose: Prompts the user for a string and ensures it is not blank.
// Used for product name, category, and company name.

    string GetNonBlankString(const string& prompt)
    {
        string input;

        while (true)
        {
            cout << prompt;
            getline(cin, input);

            bool hasRealCharacter = false;

            // Check each character to see if ANY are not spaces or tabs
            for (int i = 0; i < input.length(); i++)
            {
                if (input[i] != ' ' && input[i] != '\t')
                {
                    hasRealCharacter = true;
                    break;
                }
            }

            if (!hasRealCharacter)
            {
                cout << "Invalid value. A blank entry was received." << endl;
                continue;
            }

            return input;   // Return the original string (spaces inside are allowed)
        }
    }



// Function purpose: Prompts the user for an integer and validates numeric input and that is is within the required range.

    int GetIntInRange(const string& prompt, int minVal, int maxVal)
    {
        int value;

        while (true)
        {
            cout << prompt;

            // Try to read an integer
            if (!(cin >> value))
            {
                // User typed something like: letters, symbols, or spaces-only
                cout << "Invalid value. A non-numeric character was entered." << endl;

                cin.clear();   // Clear error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear bad input
                continue;
            }

            // Clear leftover newline
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Range check
            if (value < minVal || value > maxVal)
            {
                cout << "Invalid value. The number must be between "
                    << minVal << " and " << maxVal << " inclusive." << endl;
                continue;
            }

            return value;
        }
    }



// Prompts the user for a double and validates numeric input and within the 
// required range.  Used for product price.

double GetDoubleInRange(const string& prompt, double minVal, double maxVal)
{
    double value;

    while (true)
    {
        cout << prompt;

        if (!(cin >> value))
        {
            cout << "Invalid value. A non-numeric character was entered." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (value < minVal || value > maxVal)
        {
            cout << "Invalid value. The number must be between "
                << fixed << setprecision(2) << minVal << " and "
                << maxVal << " inclusive." << endl;
            continue;
        }

        return value;
    }
}

// Product.cpp

#include "Product.h"

// SETTERS

// Sets the product's name.
void Product::set_nameOfProduct(const string& name)
{
    _nameOfProduct = name;
}

// Sets the product's category.
void Product::set_categoryOfProduct(const string& category)
{
    _categoryOfProduct = category;
}

// Sets the price of the product.
// Validate in main() ensures the price is between 100.00 and 1000.00.
void Product::set_priceOfProduct(double price)
{
    _priceOfProduct = price;
}

// Sets the quantity on hand.
// This value is generated randomly (5–10) in main() and passed through
void Product::set_quantityOnHand(int quantity)
{
    _quantityOnHand = quantity;
}


// GETTERS

// Returns product name.
string Product::get_nameOfProduct() const
{
    return _nameOfProduct;
}

// Returns product category.
string Product::get_categoryOfProduct() const
{
    return _categoryOfProduct;
}

// Returns price of the product.
double Product::get_priceOfProduct() const
{
    return _priceOfProduct;
}

// Returns current quantity of product
int Product::get_quantityOnHand() const
{
    return _quantityOnHand;
}


// OTHER FUNCTIONS


// Calculates the total value of this product in inventory.
// Formula: price * quantity
// This function is used when generating the inventory report.
double Product::calculateValue() const
{
    return _priceOfProduct * _quantityOnHand;
}

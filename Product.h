#pragma once
// Product.h


#include <string>
using namespace std;

class Product
{
private:
    string _nameOfProduct;
    string _categoryOfProduct;
    double _priceOfProduct;
    int _quantityOnHand;

public:
    // Setters
    void set_nameOfProduct(const string& name);
    void set_categoryOfProduct(const string& category);
    void set_priceOfProduct(double price);
    void set_quantityOnHand(int quantity);

    // Getters
    string get_nameOfProduct() const;
    string get_categoryOfProduct() const;
    double get_priceOfProduct() const;
    int get_quantityOnHand() const;

 
    // Description – calculates the value of the number of this item that are on hand.
    double calculateValue() const;
};


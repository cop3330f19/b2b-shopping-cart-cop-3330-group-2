/*
Group 2 B2B 
Product Class header

Group members:

Zahir Cooper
Eric Lampley
Amani Muller
Claressa Wilson

Date last edit: 2/25/2020
*/

#include <string>

#ifndef PRODUCT_H
#define PRODUCT_H


class Product
{
private:
    int itemNo;
    std::string description;
    double price;
    int stockQuantity;
    int amountPurchased;
public:
    // Product constructor which takes 4 arguments
    Product(int,std::string,double,int,int);

    // Default Constructo
    Product();

    //  Sets item number
    void setItemNo(int);

    // Returns item number
    int getItemNo();

    // Sets item description
    void setDescription(std::string);

    // Returns item description
    std::string getDescription();

    // Sets item price
    void setPrice(double);

    // Returns item price
    double getPrice();

    // Sets item Stock Quantity
    void setStockQuantity(int);

    // Returns item Stock Quantity
    int getStockQuantity();

    // Prints info
    void const print();
    
    void setPurchaseAmount(int);
    
    int getPurchaseAmount();
};

#endif
/*
Group 2 B2B 
Product Class implementation

Group members:

Zahir Cooper
Eric Lampley
Amani Muller
Claressa Wilson

Date last edit: 2/10/2020
*/

#include <iomanip>
#include <iostream>
#include <cmath>
#include "Product.h"
#include "Customer.h"
#include "Address.h"

using namespace std;

    // Product constructor which takes 4 arguments
    Product:: Product(int itemNum, string item_description ,double item_price ,int item_quantity): 
    itemNo(itemNum), description(item_description), price(item_price) , stockQuantity(item_quantity)
    {

    }

    // Default Constructor
    Product:: Product()
    {

    }

    //  Sets item number
    void Product:: setItemNo(int itemNum)
    {
        itemNo = itemNum;
    }

    // Returns item number
    int Product:: getItemNo()
    {
        return itemNo;
    }

    // Sets item description
    void Product:: setDescription(string item_description)
    {
       description = item_description;
    }

    // Returns item description
    string Product:: getDescription()
    {
        return description;
    }

    // Sets item price
    void Product::setPrice(double item_price)
    {
        price = item_price;
    }

    // Returns item price
    double Product:: getPrice()
    {
        return price;
    }

    // Sets item Stock Quantity
    void Product:: setStockQuantity(int item_quantity)
    {
        stockQuantity = item_quantity;
    }

    // Returns item Stock Quantity
    int Product:: getStockQuantity()
    {
        return stockQuantity;
    }

    void const Product:: print()
    {
        cout << "\n--------------------------------------------" << endl;
        cout << "Item No" << setw(18) << "Description" << setw(10) << "Qty" << setw(9) << "Total" << endl;
        cout << "--------------------------------------------" << endl << endl;
        
        cout << itemNo << setw(22) << description << setw(7) << stockQuantity << setw(10) << setprecision(2) 
            << showpoint << fixed << price * stockQuantity << endl << endl;
        
       cout << "--------------------------------------------" << endl;
       cout << "Total" << setw(38) << setprecision(2) << fixed << showpoint 
         <<  price * stockQuantity << endl;
       cout << "--------------------------------------------" << endl;
      
    }





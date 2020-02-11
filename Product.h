/*
Group 2 B2B 
Product Class header

Group members:

Zahir Cooper
Eric Lampley
Amani Muller
Claressa Wilson

Date last edit: 2/10/2020
*/

#include <string>

class Product
{
private:
    int itemNo;
    std::string description;
    double price;
    int stockQuantity;
public:
    // Product constructor which takes 4 arguments
    Product(int,std::string,double,int);

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

};


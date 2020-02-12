/*
Group 2 B2B 
Customer Class header

Group members:

Zahir Cooper
Eric Lampley
Amani Muller
Claressa Wilson

Date last edit: 2/10/2020
*/
#include "Address.h"
#include <string>
#include "Product.h"

#ifndef CUSTOMER_H
#define CUSTOMER_H





class Customer
{
private:
    std::string customerNum;
    std::string customerName;
    double lineOfCredit;
    Address *corperateAddress;
public:
    Customer(std::string , std::string , double credit);
   

    Customer();
    

    // Set customer name
    void setCustomerName(std::string );
    // Set Customer number
    void setCustomerNum(std::string );
    // Set Customer Credit
    void setCustomerCredit(double);

    // Get customer name
    std:: string getCustomerName();
    // Get Customer number
    std:: string getCustomerNum();
    // Get Customer Credit Line
    double getCustomerCredit();

};

#endif
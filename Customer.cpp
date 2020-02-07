/*
Group 2 B2B 
Customer Class Implementation

*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Customer.h"

using namespace std;

class Customer
{
private:
    string customerNum;
    string customerName;
    double lineOfCredit;
    //Address *corperateAddress;
public:
    Customer:: Customer(string cus_num, string cus_name, double credit) : 
    customerName(cus_name), customerNum(cus_name), lineOfCredit(credit)
    {

    }

    Customer:: Customer()
    {

    }

    // Set customer name
    void Customer:: setCustomerName(string cus_name) {    customerName = cus_name; }
    // Set Customer number
    void Customer:: setCustomerNum(string cus_num) {    customerNum = cus_num; }
    // Set Customer Credit
    void Customer:: setCustomerCredit(double credit) {lineOfCredit = credit; }

    // Get customer name
    string Customer:: getCustomerName(){  return  customerName; }
    // Get Customer number
    string Customer:: getCustomerNum() {  return customerNum; }
    // Get Customer Credit Line
    double Customer:: getCustomerCredit() {return lineOfCredit; }

};

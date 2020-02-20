/*
Group 2 B2B 
Customer Class Implementation

Group members:

Zahir Cooper
Eric Lampley
Amani Muller
Claressa Wilson

Date last edit: 2/10/2020
*/

#include <iostream>
#include <cmath>
#include <iomanip>
#include "Customer.h"
#include "Address.h"
#include "Product.h"

#ifndef ADDRESS
#ifndef CUSTOMER
#ifndef PRODUCT
#endif
#endif
#endif


using namespace std;

Customer:: Customer(string cus_num, string cus_name, double credit, string sa, string c, string s, string zc) : 
customerName(cus_name), customerNum(cus_name), lineOfCredit(credit)
{
    
}

//Customer * asa (.....)
//asa.corperateAddress->streetAddress
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

Address * Customer:: getCorperateAddress()
{
    return corperateAddress = new Address[21];
}
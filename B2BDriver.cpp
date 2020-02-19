/*
Group 2 B2B 
Driver File

Group members:

Zahir Cooper
Eric Lampley
Amani Muller
Claressa Wilson

Date last edit: 2/18/2020
*/

#include "StringHelper.h"
#include <ctime>
#include<sstream>
#include "Address.h"
#include "Customer.h"
#include "Product.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

string generateOrderNum();

int main()
{
   double creditLimit;
   string customer, customer_name,customer_num;
   string address, city, zipcode, state, street_address;
   string associate;
    
   // global vector storing addresses
   vector<string>customer_address;

   //opening file
   ifstream inF;
   inF.open("customers.dat");
        
   // Creating Customer object
   Customer  identifier[21];
    
   //Address corperate address object
   Address cust_address[21];
    
   // Customer class pointer
   Customer *corperateAddress;
    
  for(int i = 0; i < 21; i++)
  {
      
    cout << "Enter associate name: ";
    cin >> associate;
    cout << endl;
      
    // Grabbing customers info
    // Storing in inF variable
    getline(inF, customer);
    
    // Parsing the vector to grab elements
    customer_num = StringHelper::parse(customer,'|')[0];
    customer_name = StringHelper::parse(customer,'|')[1];
    creditLimit = stod(StringHelper::parse(customer,'|')[2]);
    address = StringHelper::parse(customer, '|')[3];
    street_address = StringHelper::parse(address,',')[0];
    city = StringHelper::parse(address,',')[1];
    state = StringHelper::parse(address,',')[2];
    zipcode = StringHelper::parse(address,',')[3];
      
        
    // Looks for customer address in vector and if found pointer uses it
    if(find(customer_address.begin(),customer_address.end(),address)!= customer_address.end())
    {
        cout <<"\n We already have your address on file. ";
        corperateAddress = &address;
    }
    else
        // Adding customer address to vector
         customer_address.push_back(address);
      
    identifier[i].setCustomerNum(customer_num);
    identifier[i].setCustomerName(customer_name);
    identifier[i].setCustomerCredit(creditLimit);
  }    

	cout << endl; return 0;
    
} // main

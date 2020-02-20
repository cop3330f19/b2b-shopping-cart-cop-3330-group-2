/*
Group 2 B2B 
Address Class Implementation

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
    
   //vector storing addresses
   vector<string>customer_addresses;

   //opening file
   ifstream inF;
   inF.open("customers.dat");
        
   // Creating Customer object
   Customer  identifier[21];
    
   //Address corperate address object
   Address cust_address[21];

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
    
    identifier[i].setCustomerNum(customer_num);
    identifier[i].setCustomerName(customer_name);
    identifier[i].setCustomerCredit(creditLimit);



        
    // Looks for customer address in vector and if found pointer uses it
    if(find(customer_addresses.begin(),customer_addresses.end(),street_address)!= customer_addresses.end())
    {
      for(int i = 0; i < customer_addresses.size(); i++)
      {
        if(customer_addresses[i] == street_address)
        {
          identifier[i].getCorperateAddress()-> setStreetAddress(customer_addresses[i]);
          cout << identifier[i].getCorperateAddress()-> getStreetAddress() << endl;
        }
      }
    }
    else
        // Adding customer address to vector
         customer_addresses.push_back(street_address);
      
  }    

	cout << endl; return 0;
    
} // main

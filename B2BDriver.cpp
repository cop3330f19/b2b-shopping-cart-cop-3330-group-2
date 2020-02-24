/*Group members:

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
#include <iomanip>
#include <iostream>

using namespace std;

// Map index which address pointer to point to within Address vector
vector<int>mapAddress;

//vector storing addresses
vector<Address>customer_addresses;

string generateOrderNum()
{
    time_t now = time(0);
    string oNum;
    stringstream strstream;
    strstream << now;
    strstream >> oNum;
    return oNum;
}

void addAddress(string sa, string c, string s, string zip)
{
  //VC - this is not how you declare an object. (e.g. Student s1(fname, lname);)
  Address temp(sa,c,s,zip);

  //Looks for customer address in vector and if found returns index
  for (int j = 0; j < customer_addresses.size() ; j++)
  {
    if (customer_addresses[j].getStreetAddress() == temp.getStreetAddress())
    {
      mapAddress.push_back(j);
    }
    else 
    { 
      mapAddress.push_back(customer_addresses.size()-1);
    }    
  } 
  customer_addresses.push_back(temp); 
    
  
}

int main()
{
   double creditLimit, price;
   string customer, customer_name,customer_num;
   string address, city, zipcode, state, street_address;
   string associate, products, description;
   int itemNo, stockQuantity;

   Customer  identifier[21];
   Product   c_products[21];
   Address   c_address[21];

   //opening file
   ifstream inF;
   inF.open("customers.dat");
    
   ifstream in;
   in.open("inventory.dat");

  for(int i = 0; i < 21; i++)
  {
      
    std::cout << "Enter associate name: ";
    cin >> associate;
    std::cout << endl;
      
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
    identifier[i].setCustomerName(customer_num);
    identifier[i].setCorperateAddress(&customer_addresses[i]);
    c_address[i].setStreetAddress(street_address);
    c_address[i].setState(state);
    c_address[i].setCity(city);
    c_address[i].setZipcode(zipcode);

    addAddress(street_address,city,state,zipcode);

   
  }
    
  for(int q = 0; q < 21; q++)
  {
    getline(in, products);
    itemNo = stoi(StringHelper::parse(products,',')[0]);
    description = StringHelper::parse(products,',')[1];
    price = stod(StringHelper::parse(products,',')[2]);
    stockQuantity = stoi(StringHelper::parse(products,',')[3]);

    c_products[q].setDescription(description);
    c_products[q].setItemNo(itemNo);
    c_products[q].setPrice(price);
    c_products[q].setStockQuantity(stockQuantity);
  }

  for(int j = 0; j < 21; j++)
  {
    cout << "--------------------------------------------" << endl;
    cout << "B2B Shopping Cart" << endl;
    cout << "--------------------------------------------" << endl << endl;
    cout << "Order Number: " << generateOrderNum() << endl;
    cout << "Associate: " << associate << endl;
    cout << "Customer Number: " << identifier[j].getCustomerNum() << endl;
    cout << "Customer: " << identifier[j].getCustomerName() << endl;
    cout << "Address: " << identifier[j].getCorperateAddress() << " | " << c_address[j].getCity() << ", " << c_address[j].getState() 
    << " " << c_address[j].getZipcode() << endl;
    
    

    
  }

	cout << endl; return 0;
    
} // main


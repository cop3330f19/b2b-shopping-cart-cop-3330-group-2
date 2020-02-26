/*Group members:

Zahir Cooper
Eric Lampley
Amani Muller
Claressa Wilson

Date last edit: 2/25/2020

Purpose: This program is supposed to read customer data from a file and make a receipt.
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


Customer identifier[21];
Product  c_products[21];
Address  c_address[21];

// Global Variables so they can be used throughout program regardless of function
double creditLimit, price;
string customer, customer_name,customer_num;
string address, city, zipcode, state, street_address;
string associate, products, description;
int itemNo, stockQuantity;


// Map index which address pointer to point to within Address vector
vector <int> mapAddress;

//vector storing addresses
vector<Address>customer_addresses;

void assignVectoraddress()
{
  // assigns customer addresses based on the index its mapped to so it called later by get function
  for (int i = 0; i < mapAddress.size(); i++)
  {
    vector<Address>::iterator nAdd = customer_addresses.begin();
    advance(nAdd, mapAddress[i]);
    identifier[i].setCorperateAddress(&(*nAdd));
    
  }
  
}

string generateOrderNum()
{
    // generates random number
    time_t now = time(0);
    string oNum;
    stringstream strstream;
    strstream << now;
    strstream >> oNum;
    return oNum;
}

int addAddress(string sa, string c, string s, string zip)
{
  //Looks for customer address in vector and if found returns index
  Address temp(sa,c,s,zip);

  for (int j = 0; j < customer_addresses.size() ; j++)
  {
    if (customer_addresses[j].getStreetAddress() == temp.getStreetAddress())
    {
        return j;
    }
  } 
  customer_addresses.push_back(temp);
  return customer_addresses.size()-1;
  
}

void getCustomerFileInfo(int count , string file)
{
    // Grabbs info within file and parses it
    ifstream inF;
    inF.open(file);
        
    for(int i = 0; i < count; i++)
    {
        getline(inF,customer);
        
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
        c_address[i].setState(state);
        c_address[i].setCity(city);
        c_address[i].setZipcode(zipcode);
        
        mapAddress.push_back(addAddress(street_address,city,state,zipcode));
        assignVectoraddress();
        
    }
}

void getProductFileInfo(int count , string file)
{
  // Grabs info within product file 
    ifstream inF;
    inF.open(file);
    
     for(int q = 0; q < 21; q++)
  {
    getline(inF, products);
    itemNo = stoi(StringHelper::parse(products,',')[0]);
    description = StringHelper::parse(products,',')[1];
    price = stod(StringHelper::parse(products,',')[2]);
    stockQuantity = stoi(StringHelper::parse(products,',')[3]);

    c_products[q].setDescription(description);
    c_products[q].setItemNo(itemNo);
    c_products[q].setPrice(price);
    c_products[q].setStockQuantity(stockQuantity);
  }
}

int countLinesInFile(string f)
{
  // Counts lines within file
  int count = 0;
  string line;
 
    ifstream file;
    file.open(f);
    
    while (getline(file, customer))
      count++;

    return count;
    
    file.close();
}

bool checkCustomerStuff(double credit, int price, int stock)
{
  // Checks to make sure customer items and credit are vaild
    int creditLeftOver;
    
    creditLeftOver = credit - (price * stock);
    
    if(creditLeftOver >= 0 && stock >= 0)
    {
        return true;
    }
    else if(creditLeftOver < 0)
    {
        return false;
    }
    else if(stock < 0)
    {
        return false;
    }
}

  

int main()
{ 
  int filecount = countLinesInFile("customers.dat");
    
  int productFilecount = countLinesInFile("inventory.dat");
   
  getCustomerFileInfo(filecount,"customers.dat");
    
  getProductFileInfo(productFilecount, "inventory.dat");
 
  
    
    
  for(int j = 0; j < 21; j++)
  {
    ifstream file(generateOrderNum());
      
     identifier[j].print();
     if (checkCustomerStuff(identifier[j].getCustomerCredit(),c_products[j].getPrice(),c_products[j].getStockQuantity()))
     {
       cout << "Sorry you dont't have any credit left to buy them items " << endl;
     }
     else 
     {
       c_address[j].print();
       c_products[j].print();
       cout << "Remaining Credit" << setw(28) << setprecision(2) << fixed << creditLimit - (price * stockQuantity) 
           << endl << endl;
     }
 
  }

	cout << endl; return 0;
    
} // main


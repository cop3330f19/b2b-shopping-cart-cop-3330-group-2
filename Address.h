/*
Group 2 B2B 
Address Class header

Group members:

Zahir Cooper
Eric Lampley
Amani Muller
Claressa Wilson

Date last edit: 2/10/2020
*/

#include "Product.h"
#include <string>


#ifndef ADDRESS_H
#define ADDRESS_H



class Address
{
private:
    std::string streetAddress;
    std::string city; 
    std::string zipCode;
    std::string state; 
public:
    // Constructor that initalizes parameters
    Address(std::string, std::string, std::string, std::string);

    // Default constructor
    Address();

    // Sets street name
    void setStreetAddress(std::string);

    // Returns street name
    std::string getStreetAddress();

    // Sets city name
    void setCity(std::string);

    // Returns city name
    std::string getCity();

    // Sets state name
    void setState(std::string);

    //Gets state name
    std::string getState();

    // Sets zipcode as a string
    void setZipcode(std::string);

    // Returns Zipcode as a string
    std::string getZipcode();
    
    void print();

};

#endif


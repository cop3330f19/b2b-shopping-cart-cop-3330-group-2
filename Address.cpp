/*
Group 2 B2B 
Address Class Implementation

Group members:

Zahir Cooper
Eric Lampley
Amani Muller
Claressa Wilson

Date last edit: 2/25/2020
*/

#include <iomanip>
#include <iostream>
#include "Address.h"
#include  "Customer.h"
#include "Product.h"

#ifndef ADDRESS
#ifndef CUSTOMER
#ifndef PRODUCT
#endif
#endif
#endif

using namespace std;

// Constructor that initalizes parameters
Address:: Address(string sa, string c, string s, string zc) : streetAddress(sa), city(c), state(s), zipCode(zc)
{

}

    // Default constructor
Address:: Address()
{

}

// Sets street name
void Address:: setStreetAddress(string sa)
{
    streetAddress = sa;
}

// Returns street name
string Address:: getStreetAddress()
{
    return streetAddress;
}

// Sets city name
void Address:: setCity(string c)
{
    city = c;
}

// Returns city name
string Address:: getCity()
{
    return city;
}

// Sets state name
void Address:: setState(string s)
{
    state = s;
}

//Gets state name
string Address:: getState()
{
    return state;
}

// Sets zipcode as a string
void Address:: setZipcode(string zc)
{
    zipCode = zc;
}

// Returns Zipcode as a string
string Address:: getZipcode()
{
    return zipCode;
}

void Address:: print()
{
    cout << city << ", " << state << " " << zipCode;
}
    

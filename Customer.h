/*
Group 2 B2B 
Customer Class header

*/

#include <string>


class Customer
{
private:
    std::string customerNum;
    std::string customerName;
    double lineOfCredit;
    //Address *corperateAddress;
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

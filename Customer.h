#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    int idCustomer;
    std::string name;
    std::string phoneNumber;

public:
    Customer(int id, std::string n, std::string phone = "-");

    int getId() const;
    std::string getName() const;
    std::string getPhoneNumber() const;

    void setName(std::string newName);
    void setPhoneNumber(std::string newPhone);
};

#endif
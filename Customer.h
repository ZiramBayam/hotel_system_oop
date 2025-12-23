#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

class Customer {
private:
    int idCustomer;
    std::string name;

public:
    Customer(int id, std::string n);

    int getId() const;
    std::string getName() const;

    void setName(std::string newName);
};

#endif
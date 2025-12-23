#include "Customer.h"

Customer::Customer(int id, std::string n) 
    : idCustomer(id), name(n) {}

int Customer::getId() const { return idCustomer; }
std::string Customer::getName() const { return name; }

void Customer::setName(std::string newName) {
    this->name = newName;
}
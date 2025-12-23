#include "Customer.h"

Customer::Customer(int id, std::string n, std::string phone) 
    : idCustomer(id), name(n), phoneNumber(phone) {}

int Customer::getId() const { return idCustomer; }
std::string Customer::getName() const { return name; }
std::string Customer::getPhoneNumber() const { return phoneNumber; }

void Customer::setName(std::string newName) {
    this->name = newName;
}

void Customer::setPhoneNumber(std::string newPhone) {
    this->phoneNumber = newPhone;
}
#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include "Customer.h"
#include "Room.h"
#include "Payment.h"

class Reservation {
private:
    int idReservation;
    Customer* customer;
    Room* room;
    std::string checkIn, checkOut;
    Payment* payment;

public:
    Reservation(int id, Customer* c, Room* r, std::string in, std::string out);
    ~Reservation();

    int getId() const;
    Room* getRoom() const;
    std::string getCheckIn() const;
    std::string getCheckOut() const;
    Customer* getCustomer() const;

    void createPayment(IPaymentStrategy* method);
    void printDetail();
};

#endif
#include "Reservation.h"
#include <iostream>
#include <iomanip>

using namespace std;

Reservation::Reservation(int id, Customer* c, Room* r, string in, string out)
    : idReservation(id), customer(c), room(r), checkIn(in), checkOut(out), payment(nullptr) {}

Reservation::~Reservation() {
    if (payment) delete payment;
}

int Reservation::getId() const { return idReservation; }
Room* Reservation::getRoom() const { return room; }
string Reservation::getCheckIn() const { return checkIn; }
string Reservation::getCheckOut() const { return checkOut; }
Customer* Reservation::getCustomer() const { return customer; }

void Reservation::createPayment(IPaymentStrategy* method) {
    double total = room->getPrice();
    payment = new Payment(idReservation, total, method);
    payment->process();
}

void Reservation::printDetail() {
    cout << "ID: " << idReservation 
         << " | Guest: " << left << setw(10) << customer->getName()
         << " | Room: " << room->getId() 
         << " | Date: " << checkIn << " to " << checkOut << endl;
}
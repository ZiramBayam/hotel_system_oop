#include "Reservation.h"
#include "DateUtils.h"
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
    int nights = DateUtils::getDurationDays(checkIn, checkOut);
    
    if (nights <= 0) nights = 1;

    double roomPrice = room->getPrice();
    double total = roomPrice * nights;

    cout << "   [INFO] Durasi: " << nights << " malam @ Rp " << (long)roomPrice << endl;

    payment = new Payment(idReservation, total, method);
    payment->process();
}

void Reservation::printDetail() {
    int nights = DateUtils::getDurationDays(checkIn, checkOut);
    
    cout << "ID: " << idReservation 
         << " | " << left << setw(10) << customer->getName()
         << " | Room: " << room->getId()
         << " | " << checkIn << " s/d " << checkOut 
         << " (" << nights << " Night)" << endl;
}
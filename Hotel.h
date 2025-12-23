#ifndef HOTEL_H
#define HOTEL_H

#include <vector>
#include "Room.h"
#include "Customer.h"
#include "Reservation.h"

class Hotel {
private:
    std::vector<Room*> roomList;
    std::vector<Customer*> customerList;
    std::vector<Reservation*> reservationList;
    static Hotel* instance;

    Hotel(); 

public:
    static Hotel* getInstance();
    
    bool addRoom(Room* r);
    bool addCustomer(Customer* c);
    
    // Helper untuk cek keberadaan data
    Customer* getCustomer(int id); 
    Room* getRoom(int id);

    void createReservation(int cId, int rId, std::string inDate, std::string outDate, bool withBreakfast, int paymentType);
    void cancelReservation(int resId);
    void showDashboard();
    void checkAvailability(std::string in, std::string out);
    void showCustomerHistory(int cId);
    void editCustomer(int cId, std::string newName);
    void showAllRooms();
    void showAllCustomers();
    void showAllReservations();
};

#endif
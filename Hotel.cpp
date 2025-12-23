#include "Hotel.h"
#include "DateUtils.h"
#include "Payment.h" 
#include <iostream>
#include <iomanip>

using namespace std;

Hotel* Hotel::instance = nullptr;

Hotel::Hotel() {}

Hotel* Hotel::getInstance() {
    if (!instance) instance = new Hotel();
    return instance;
}

bool Hotel::addRoom(Room* r) {
    if (getRoom(r->getId()) != nullptr) {
        return false;
    }
    roomList.push_back(r);
    return true;
}

bool Hotel::addCustomer(Customer* c) {
    if (getCustomer(c->getId()) != nullptr) {
        return false;
    }
    customerList.push_back(c);
    return true;
}

Room* Hotel::getRoom(int id) {
    for (auto r : roomList) {
        if (r->getId() == id) return r;
    }
    return nullptr;
}

Customer* Hotel::getCustomer(int id) {
    for (auto c : customerList) if (c->getId() == id) return c;
    return nullptr;
}

void Hotel::createReservation(int cId, int rId, string inDate, string outDate, bool withBreakfast, int paymentType) {
    if (inDate >= outDate) {
        cout << ">> ERROR : Tanggal Check-Out harus setelah Check-In!" << endl;
        return;
    }

    Customer* cust = getCustomer(cId);
    Room* room = nullptr;
    for (auto r : roomList) if (r->getId() == rId) room = r;

    if (!cust || !room) {
        cout << ">> ERROR : Customer atau Room tidak valid!" << endl;
        return;
    }

    for (auto res : reservationList) {
        if (res->getRoom()->getId() == rId) {
            if (DateUtils::isOverlap(inDate, outDate, res->getCheckIn(), res->getCheckOut())) {
                cout << ">> GAGAL : Kamar " << rId << " Penuh di tanggal tsb!" << endl;
                return;
            }
        }
    }

    if (withBreakfast) room = new BreakfastDecorator(room);

    int newId = reservationList.size() + 1;
    Reservation* res = new Reservation(newId, cust, room, inDate, outDate);
    IPaymentStrategy* strategy = nullptr;
    
    if (paymentType == 2) {
        strategy = new TransferPayment(); // Gunakan strategi Transfer
    } else {
        strategy = new CashPayment(); // Default ke Cash
    }
    res->createPayment(strategy);
    
    reservationList.push_back(res);
    cout << ">> SUKSES : Booking ID " << newId << " berhasil dibuat!" << endl;
}

void Hotel::cancelReservation(int resId) {
    for (auto it = reservationList.begin(); it != reservationList.end(); ++it) {
        if ((*it)->getId() == resId) {
            delete *it;
            reservationList.erase(it);
            cout << ">> SUKSES : Reservasi dihapus." << endl;
            return;
        }
    }
    cout << ">> ERROR : ID tidak ditemukan." << endl;
}

void Hotel::showDashboard() {
    double totalRevenue = 0;
    
    cout << "\n========== DASHBOARD HOTEL ==========" << endl;
    cout << " Total Kamar       : " << roomList.size() << endl;
    cout << " Total Tamu        : " << customerList.size() << endl;
    cout << " Booking Aktif     : " << reservationList.size() << endl;
    cout << "=======================================" << endl;
}

void Hotel::checkAvailability(string in, string out) {
    cout << "\n--- HASIL PENCARIAN KAMAR (" << in << " s.d. " << out << ") ---" << endl;
    bool foundAny = false;

    for (auto r : roomList) {
        bool isBooked = false;
        for (auto res : reservationList) {
            if (res->getRoom()->getId() == r->getId()) {
                if (DateUtils::isOverlap(in, out, res->getCheckIn(), res->getCheckOut())) {
                    isBooked = true;
                    break;
                }
            }
        }

        if (!isBooked) {
            r->showRow();
            foundAny = true;
        }
    }

    if (!foundAny) cout << ">> MAAF, SEMUA KAMAR PENUH DI TANGGAL TERSEBUT." << endl;
}

void Hotel::showCustomerHistory(int cId) {
    Customer* c = getCustomer(cId);
    if (!c) { cout << "Customer tidak ditemukan." << endl; return; }

    cout << "\n--- RIWAYAT BOOKING: " << c->getName() << " ---" << endl;
    bool found = false;
    for (auto res : reservationList) {
        if (res->getCustomer()->getId() == cId) {
            res->printDetail();
            found = true;
        }
    }
    if (!found) cout << "(Belum ada riwayat pemesanan)" << endl;
}

void Hotel::editCustomer(int cId, string newName) {
    Customer* c = getCustomer(cId);

    if (c) {
        c->setName(newName);
        
        cout << ">> SUKSES : Data tamu berhasil diperbarui." << endl;
        cout << ">> Nama Baru: " << c->getName() << endl;
    } else {
        cout << ">> ERROR : ID Tamu tidak ditemukan!" << endl;
    }
}

void Hotel::showAllRooms() {
    cout << "\n--- DAFTAR SEMUA KAMAR ---" << endl;
    for (auto r : roomList) r->showRow();
}

void Hotel::showAllCustomers() {
    cout << "\n--- DAFTAR SEMUA CUSTOMER ---" << endl;
    for (auto c : customerList) {
        cout << "ID: " << c->getId() << " | Nama: " << c->getName() << endl;
    }
}

void Hotel::showAllReservations() {
    cout << "\n--- SEMUA RESERVASI AKTIF ---" << endl;
    if (reservationList.empty()) cout << "(Kosong)" << endl;
    else for (auto r : reservationList) r->printDetail();
}
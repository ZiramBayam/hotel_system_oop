#include <iostream>
#include <limits>
#include <string>
#include "Hotel.h"

using namespace std;

int getValidInt(string prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            return value;
        } else {
            cout << ">> ERROR : Input tidak valid! Harap masukkan angka." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

string getValidString(string prompt) {
    string value;
    cout << prompt;
    cin >> ws;
    getline(cin, value);
    return value;
}

void pressEnter() {
    cout << "\n>> Tekan [ENTER] untuk kembali...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

int main() {
    Hotel* hotel = Hotel::getInstance();

    // Data Dummy Awal
    hotel->addRoom(RoomFactory::createRoom(1, 101));
    hotel->addRoom(RoomFactory::createRoom(2, 201)); 
    hotel->addCustomer(new Customer(1, "Budi Santoso"));
    hotel->addCustomer(new Customer(2, "Siti Aminah"));

    int mainChoice;
    do {
        
        cout << "\n==============================================" << endl;
        cout << "    GRAND HOTEL SYSTEM                          " << endl;
        cout << "==============================================" << endl;
        cout << " [1] DASHBOARD & STATISTIK" << endl;
        cout << " [2] MANAJEMEN KAMAR" << endl;
        cout << " [3] MANAJEMEN TAMU" << endl;
        cout << " [4] TRANSAKSI RESERVASI" << endl;
        cout << " [0] KELUAR" << endl;
        cout << "==============================================" << endl;
        
        mainChoice = getValidInt("Pilih Menu: ");

        if (mainChoice == 1) {
            hotel->showDashboard();
            pressEnter();
        }
        else if (mainChoice == 2) {
            int subChoice;
            cout << "\n--- MANAJEMEN KAMAR ---" << endl;
            cout << "1. Lihat Semua Kamar" << endl;
            cout << "2. Cek Ketersediaan" << endl;
            cout << "3. (+ Tambah Kamar Baru)" << endl;
            
            subChoice = getValidInt("Pilih: ");

            if (subChoice == 1) {
                hotel->showAllRooms();
            } 
            else if (subChoice == 2) {
                string in = getValidString("Check-In  (YYYY-MM-DD): ");
                string out = getValidString("Check-Out (YYYY-MM-DD): ");
                hotel->checkAvailability(in, out);
            } 
            else if (subChoice == 3) {
                int type = getValidInt("Pilih Tipe (1.Deluxe, 2.Superior, 3.Suite): ");
                int id = getValidInt("Masukkan Nomor Kamar (ID): ");

                Room* newRoom = RoomFactory::createRoom(type, id);

                if (newRoom) {
                    if (hotel->addRoom(newRoom)) {
                        cout << ">> SUKSES : Kamar " << id << " berhasil ditambahkan." << endl;
                    } else {
                        cout << ">> GAGAL : Nomor Kamar " << id << " SUDAH ADA! Ganti nomor lain." << endl;
                        delete newRoom;
                    }
                } else {
                    cout << ">> ERROR : Tipe kamar tidak valid!" << endl;
                }
            }
            pressEnter();
        }
        else if (mainChoice == 3) {
            int subChoice;
            cout << "\n--- MANAJEMEN TAMU ---" << endl;
            cout << "1. Lihat Daftar Tamu" << endl;
            cout << "2. (+ Tambah Tamu Baru)" << endl;
            cout << "3. Cek Riwayat Tamu" << endl;
            subChoice = getValidInt("Pilih: ");

            if (subChoice == 1) {
                hotel->showAllCustomers();
            } 
            else if (subChoice == 2) {
                int id = getValidInt("ID Unik (KTP/Member): ");
                string name = getValidString("Nama Lengkap: ");
                
                Customer* newCust = new Customer(id, name);

                if (hotel->addCustomer(newCust)) {
                    cout << ">> SUKSES : Tamu terdaftar." << endl;
                } else {
                    cout << ">> GAGAL : ID Customer " << id << " SUDAH TERDAFTAR!" << endl;
                    delete newCust;
                }
            }
            else if (subChoice == 3) {
                int id = getValidInt("Masukkan ID Tamu: ");
                hotel->showCustomerHistory(id);
            }
            pressEnter();
        }
        else if (mainChoice == 4) {
            int subChoice;
            cout << "\n--- TRANSAKSI RESERVASI ---" << endl;
            cout << "1. Booking Baru" << endl;
            cout << "2. Batalkan Booking" << endl;
            cout << "3. Lihat Booking Aktif" << endl;
            subChoice = getValidInt("Pilih: ");

            if (subChoice == 1) {
                hotel->showAllCustomers();
                cout << "-----------------------------------" << endl;
                
                int cId = getValidInt("ID Customer: ");
                int rId = getValidInt("ID Kamar   : ");
                string in = getValidString("Check-In (YYYY-MM-DD) : ");
                string out = getValidString("Check-Out (YYYY-MM-DD): ");
                string optStr = getValidString("Tambah Breakfast (+50k)? (y/n): ");
                
                char opt = optStr.empty() ? 'n' : optStr[0];
                
                hotel->createReservation(cId, rId, in, out, (opt=='y' || opt=='Y'));
            } 
            else if (subChoice == 2) {
                hotel->showAllReservations(); 
                int rId = getValidInt("Masukkan ID RESERVASI: ");
                hotel->cancelReservation(rId);
            } 
            else if (subChoice == 3) {
                hotel->showAllReservations();
            }
            pressEnter();
        }
        else if (mainChoice != 0) {
            cout << ">> ERROR : Pilihan tidak valid." << endl;
            pressEnter(); // Pause biar user baca errornya
        }

    } while (mainChoice != 0);

    return 0;
}
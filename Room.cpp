#include "Room.h"

using namespace std;

// Base Room Impl
Room::Room(int id, string type, double p) : idRoom(id), roomType(type), price(p) {}
Room::~Room() {}
double Room::getPrice() { return price; }
string Room::getDescription() { return roomType; }
int Room::getId() const { return idRoom; }
void Room::showRow() {
    cout << "| " << setw(5) << idRoom << " | " << left << setw(20) << getDescription() 
         << " | Rp " << setw(10) << (long)getPrice() << " |" << endl;
}

// Subclasses
DeluxeRoom::DeluxeRoom(int id) : Room(id, "Deluxe Room", 500000) {}
SuperiorRoom::SuperiorRoom(int id) : Room(id, "Superior Room", 750000) {}
SuiteRoom::SuiteRoom(int id) : Room(id, "Suite Room", 1500000) {}

// Decorator Impl
RoomDecorator::RoomDecorator(Room* room) : Room(room->getId(), room->getDescription(), room->getPrice()) {
    this->decoratedRoom = room;
}
double RoomDecorator::getPrice() { return decoratedRoom->getPrice(); }
string RoomDecorator::getDescription() { return decoratedRoom->getDescription(); }

BreakfastDecorator::BreakfastDecorator(Room* room) : RoomDecorator(room) {}
double BreakfastDecorator::getPrice() { return decoratedRoom->getPrice() + 50000; }
string BreakfastDecorator::getDescription() { return decoratedRoom->getDescription() + " + Breakfast"; }

// Factory Impl
Room* RoomFactory::createRoom(int type, int id) {
    switch(type) {
        case 1: return new DeluxeRoom(id);
        case 2: return new SuperiorRoom(id);
        case 3: return new SuiteRoom(id);
        default: return nullptr;
    }
}
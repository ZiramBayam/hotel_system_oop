#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <iostream>
#include <iomanip>

// Base Component
class Room {
protected:
    int idRoom;
    std::string roomType;
    double price;

public:
    Room(int id, std::string type, double p);
    virtual ~Room();

    virtual double getPrice();
    virtual std::string getDescription();
    int getId() const;
    void showRow();
};

// Concrete Components
class DeluxeRoom : public Room {
public:
    DeluxeRoom(int id);
};

class SuperiorRoom : public Room {
public:
    SuperiorRoom(int id);
};

class SuiteRoom : public Room {
public:
    SuiteRoom(int id);
};

// Decorator Base
class RoomDecorator : public Room {
protected:
    Room* decoratedRoom;
public:
    RoomDecorator(Room* room);
    double getPrice() override;
    std::string getDescription() override;
};

// Concrete Decorators
class BreakfastDecorator : public RoomDecorator {
public:
    BreakfastDecorator(Room* room);
    double getPrice() override;
    std::string getDescription() override;
};

// Factory
class RoomFactory {
public:
    static Room* createRoom(int type, int id);
};

#endif
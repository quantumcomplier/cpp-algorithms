#include "Room.h"
#include <iomanip>
#include <iostream>
#include <cstring>


//Constructors:
Room::Room()
{
	roomStatus = "";
	roomType = "";
	roomCapacity = 0;
	roomNumber = 0;
	roomRate = 0;
}

Room::Room(std::string status, std::string type, int capacity, int number, int rate)
{
	Room::roomStatus = status;
	Room::roomType = type;
	Room::roomCapacity = capacity;
	Room::roomNumber = number;
	Room::roomRate = rate;
}

// setters:
void Room::setRoomStatus(const std::string& status)
{
	roomStatus = status;
}

void Room::setRoomType(const std::string& type)
{
	roomType = type;
}

void Room::setRoomCapacity(int capacity)
{
	roomCapacity = capacity;
}

void Room::setRoomNumber(int number)
{
	roomNumber = number;
}

void Room::setRoomRate(int rate)
{
	roomRate = rate;
}

// getters:
std::string  Room::getRoomStatus() const
{
	return roomStatus;
}

std::string Room::getRoomType() const
{
	return roomType;
}

int Room::getRoomCapacity() const
{
	return roomCapacity;
}

int Room::getRoomNumber() const
{
	return roomNumber;
}

int Room::getRoomRate() const
{
	return roomRate;
}

// Additional functions

// Creates and returns full name by the room type (A returns Available)
std::string Room::retrieveRoomStatusDescription() const
{
	if (roomStatus == "A")
		return "Available";
	if (roomStatus == "O")
		return "Occupied";
	if (roomStatus == "R")
		return "Reserved";
	else
		return "Error retrieving room status.";
}

// Generates full text for the room type (U returns Suite)
std::string Room::retrieveRoomTypeDescription() const
{
	if (roomType == "S")
		return "Single";
	if (roomType == "D")
		return "Double";
	if (roomType == "U")
		return "Suite";
	else
		return "Error retrieving room type.";
}

// Outputs informationfor current room (will be called by Hotel.displayRoomsList() )
void Room::displayRoomInfo() const
{
	std::cout << std::left;
	std::cout << std::setw(8) << roomNumber <<
		std::setw(10) << roomType <<
		std::setw(10) << roomCapacity <<
		std::setw(10) << roomStatus <<
		std::setw(5) << roomRate << "\n";

}
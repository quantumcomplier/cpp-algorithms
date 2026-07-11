// Purpose of the Room.h and room.cpp is to encapsulate information on a single rooms and create
// functions to manipulate the data.

#pragma once

#include <string>
#include<iostream>

class Room
{
public:
	// No parameter constructor:
	Room();

	//Constructor with parameters:
	Room(std::string status, std::string type, int capacity, int number, int rate);

	// setters:
	void setRoomStatus(const std::string&);
	void setRoomType(const std::string&);
	void setRoomCapacity(int);
	void setRoomNumber(int);
	void setRoomRate(int);

	// getters:
	std::string  getRoomStatus() const;
	std::string getRoomType() const;
	int getRoomCapacity() const;
	int getRoomNumber() const;
	int getRoomRate() const;

	// Additional functions

	// Creates and returns full name by the room type (A returns Available)
	std::string retrieveRoomStatusDescription() const;

	// Generates full text for the room type (U returns Suite)
	std::string retrieveRoomTypeDescription() const;

	// Outputs information for current room (will be called by Hotel.displayRoomsList() )
	void displayRoomInfo() const;

	


private:
	// Displays status of the room as Available (A), Occupied (O), or Reserved (R) [can't be blank
	// and must be an uppercase character].
	std::string roomStatus;

	// String to identify the type of room and Single (S), Double (D), or Suite (U) [can't be blank
	// and must be an uppercase character].
	std::string roomType;

	// Displays the max occupancy for the room (Must be numeric, +, and between 1 and 4 inclusive)
	int roomCapacity;

	// Variable for the room number (Must be numeric, +, and 3 digits in length. Between 101 -199, 
	// 201-299, or 301-399 all inclusive of ranges)
	int roomNumber;

	// Stores rate for the room (Must be numeric, + and one of these values: 101, 199, 268)
	int roomRate;
};
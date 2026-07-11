// Purpose of the header and accompanying .cpp file (Hotel) is ti encapsulate data about a hotel
// and its rooms. Functions will manipulate the data.

#pragma once

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Room.h"

class Hotel
{
public:
	// Zero argument constructor
	Hotel();

	// Constructor w/ variables  to initialize:
	Hotel(std::string name, int minRooms, std::string city, std::string state,
		std::string opened);

	// Setters:
	void setNameHotel(const std::string&);
	void setMinNumberOfRooms(int);
	void setCityHotel(const std::string&);
	void setStateHotel(const std::string&);
	void setOpenedForBusiness(const std::string&);

	//Getters:
	std::string getNameHotel() const;
	int getMinNumberOfRooms() const;
	std::string getCityHotel() const;
	std::string getStateHotel() const;
	std::string getOpenedForBusiness() const;

	//additional functions
	
	//Room object - accepts a single room and adds to vector
	void addRoom(const Room&);

	//Outputs info about hotel and lists room info
	void displayRoomsList() const;

	// returns the number of rooms in the hotel
	int retrieveNumberOfRooms() const;

	// Sorts Rooms by room number (not const bc it sorts vector)
	void sortRooms();

	// Combines and returns city and state in desired format
	std::string combineStateAndCity() const;


private:
	// Var to store name of hotel (can't be blank)
	std::string nameHotel;	

	// Min # of rooms processed before user can exit. (MUST be numeric, +, and between 3-5 inclusive)
	int minNumberOfRooms;   

	// Stores city where hotel is (Cant be blank)
	std::string cityHotel;

	// Stores State where hotel is (can't be blank)
	std::string stateHotel;

	// Stores date opened (can't be blank)
	std::string openedForBusiness;

	// Vector to store data on rooms
	std::vector<Room> listOfRooms;


};


#include "Hotel.h"
#include <iomanip>
#include <iostream>
#include <cstring>
#include <algorithm>

// Zero argument constructor
Hotel::Hotel()
{
	nameHotel = "";
	minNumberOfRooms = 0;
	cityHotel = "";
	stateHotel = "";
	openedForBusiness = "";
}

// Constructor w/ variables  to initialize:
Hotel::Hotel(std::string name, int minRooms, std::string city, std::string state,
	std::string opened)
{
	nameHotel = name;
	minNumberOfRooms = minRooms;
	cityHotel = city;
	stateHotel = state;
	openedForBusiness = opened;
}

// Setters:
void Hotel::setNameHotel(const std::string& name)
{
	nameHotel = name;
}

void Hotel::setMinNumberOfRooms(int number)
{
	minNumberOfRooms = number;
}

void Hotel::setCityHotel(const std::string& city)
{
	cityHotel = city;
}

void Hotel::setStateHotel(const std::string& state)
{
	stateHotel = state;
}

void Hotel::setOpenedForBusiness(const std::string& opened)
{
	openedForBusiness = opened;
}

//Getters:
int Hotel::getMinNumberOfRooms() const
{
	return minNumberOfRooms;
}

std::string Hotel::getCityHotel() const
{
	return cityHotel;
}

std::string Hotel::getStateHotel() const
{
	return stateHotel;
}

std::string Hotel::getOpenedForBusiness() const
{
	return openedForBusiness;
}

//additional functions

//Room object - accepts a single room and adds to vector
void Hotel::addRoom(const Room& room)
{
	listOfRooms.push_back(room);
}

//Outputs info about hotel and lists room info
void Hotel::displayRoomsList() const
{
	std::cout << "\n" << nameHotel << "\n";
	std::cout << combineStateAndCity() << "\n\n";

	std::cout << "Rooms Status\n\n";

	if (listOfRooms.empty())
	{
		std::cout << "No rooms defined for this hotel.\n";
		return;
	}

	std::cout << std::left
		<< std::setw(10) << "Room #"
		<< std::setw(10) << "Type"
		<< std::setw(10) << "Capacity"
		<< std::setw(10) << "Status"
		<< std::setw(10) << "Rate"
		<< "\n";

	for (const Room& r : listOfRooms)
	{
		r.displayRoomInfo();
	}
}

// returns the number of rooms in the hotel
int Hotel::retrieveNumberOfRooms() const
{
	return static_cast<int>(listOfRooms.size());
}

// Sorts Rooms by room number (not const bc it sorts vector)
void Hotel::sortRooms()
{
	std::sort(listOfRooms.begin(), listOfRooms.end(), [](const Room& a, const Room& b)
		{
			return a.getRoomNumber() < b.getRoomNumber();
		});
}

// Combines and returns city and state in desired format
std::string Hotel::combineStateAndCity() const
{
	return cityHotel + ", " + stateHotel; 
}

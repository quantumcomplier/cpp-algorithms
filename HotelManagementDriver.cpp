// Briceno-Dav-Lab 4.cpp -- Use composition to create a Hotel Rooms Availability report program
//CSIS 112 B01 202630


//<Sources if necessary>
// Sorting: https://stackoverflow.com/questions/5122804/how-to-sort-with-a-lambda
// Prof. William's code snippets

//Include statements 
#include <iostream> 
#include <string> 
#include <iomanip>
#include "Hotel.h"
#include "Room.h"
#include "MiscCommon.h"
#include <limits>

using namespace std;


//Global declarations: Constants and type definitions only -- no variables
//Function prototypes 

bool validateDate(int month, int day, int year);
void managerMenu(Hotel& ht);

int main()
{
	//In cout statement below SUBSTITUTE your name and lab number
	cout << "David Briceno - Lab 4" << endl << endl;

	//Variable declarations
	string name, city, state, opened;
	int day, month, year;
	int minRooms = 0;
	bool isValid = false;
	bool valid = false;

	//Program logic

// Create Hotel object
	Hotel ht;

	// Create input screen with formatting to match example
	cout << setw(26) << right << "Hotel Information Entry" << endl << endl;

	// Get Hotel name and validate for blank entry
	do
	{
		cout << setw(26) << right << "Name :" << " ";
		getline(cin, name);
	} while (!validateRequiredStringEntry(name, "Blank entry. Please try again.\n"));

	// store hotel object name
	ht.setNameHotel(name);

	// Get date opened for business and validate date using leap year & valid date algorithm
	string dateInput;

	do
	{
		cout << setw(26) << right << "Opened for Business  " << endl;
		cout << setw(26) << right << "(MM/DD/YYYY) :";
		cin >> dateInput;

		// Find slashes
		size_t pos1 = dateInput.find('/');
		size_t pos2 = dateInput.find('/', pos1 + 1);

		if (pos1 == string::npos || pos2 == string::npos)
		{
			cout << "Invalid date. Try Again.\n";
			continue;
		}
				
		
		// Extract month/day/year
		month = stoi(dateInput.substr(0, pos1));
		day = stoi(dateInput.substr(pos1 + 1, pos2 - pos1 - 1));
		year = stoi(dateInput.substr(pos2 + 1));

		valid = validateDate(month, day, year);

		if (!valid)
			cout << "Invalid date. Try Again.\n";

	} while (!valid);

	// Combine date variables into final string output:
	opened = to_string(month) + "/" + to_string(day) + "/" + to_string(year);

	// set Hotel opening date
	ht.setOpenedForBusiness(opened);

	// Get minimum number of rooms to input and validate for required range
	do
	{
		cout << setw(26) << right << "Minimum number of rooms  " << " " << endl;
		cout << setw(26) << right << "(3-5 inclusive) :" << " ";
		cin >> minRooms;

		if (minRooms < 3 || minRooms > 5)
			cout << "Invalid number of Rooms. Try Again.";

	} while (minRooms < 3 || minRooms > 5);

	// Set hotel object min rooms
	ht.setMinNumberOfRooms(minRooms);

	clearCin(); // Clear newline from numeric input

	// Get input for city and check for blank entry
	do
	{
		cout << setw(26) << right << "City :" << " ";
		getline(cin, city);
	} while (!validateRequiredStringEntry(city, "Blank entry. Please try again.\n"));

	// set Hotel object city
	ht.setCityHotel(city);

	//Get input for state and check for blank entry

	do
	{
		cout << setw(26) << right << "State :" << " ";
		getline(cin, state);
	} while (!validateRequiredStringEntry(state, "Blank entry. Please try again.\n"));

	// Set hotel object state
	ht.setStateHotel(state);

	pauseUntilUserIsReady();


	managerMenu(ht);



	//Closing program statements

	system("pause");
	return 0;
} //END MAIN


//Function definitions

bool validateDate(int month, int day, int year)
{
	bool leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (leap) daysInMonth[1] = 29;

	if (month < 1 || month > 12) return false;
	if (year < 1900 || year > 2026) return false;
	if (day < 1 || day > daysInMonth[month - 1]) return false;

	return true;
}


void managerMenu(Hotel& ht)
{
	char choice;
	do
	{

		cout << "Hotel Room Management Menu:\n\n";

		cout << "I - Update a Room\n";
		cout << "R - List Status of Rooms\n";
		cout << "E - Exit\n\n";


		cout << "Selection: ";
		cin >> choice;
		clearCin(); // clear buffer before switch input

		switch (choice)
		{
		case 'I':
		case 'i':

			// Input Room number
		{
			Room rm;
			int rNum;

			cout << setw(41) << right << "Room Information Update Entry" << endl << endl;
			cout << setw(40) << "Number  " << endl;
			cout << setw(40) << "(101-199, 201-299, 301-399 inclusive) :";

			// Room validation
			do
			{
				cin >> rNum;

				if (cin.fail() || !((rNum >= 101 && rNum <= 199) || (rNum >= 201 && rNum <= 299)
					|| (rNum >= 301 && rNum <= 399)))
				{
					cout << "Invalid room number. Try again.\n";
					clearCin();
					cout << setw(40) << "(101-199, 201-299, 301-399 inclusive) :";
				}
			} while (!((rNum >= 101 && rNum <= 199) || (rNum >= 201 && rNum <= 299)
				|| (rNum >= 301 && rNum <= 399)));

			// call function from room.cpp to set room number in room object
			rm.setRoomNumber(rNum);

			// Input room capacity
			int cap;

			cout << setw(40) << "Capacity  " << endl;
			cout << setw(40) << "(1-4 inclusive) :";

			// Capacity Validation
			do
			{
				cin >> cap;

				if (cin.fail() || !(cap >= 1 && cap <= 4))
				{
					cout << "Invalid value for room capacity. Try Again.\n";
					clearCin();
					cout << setw(40) << "(1-4 inclusive) :";
				}
			} while (!(cap >= 1 && cap <= 4));

			//Call function to set room capacity in room object
			rm.setRoomCapacity(cap);

			// Input Room Type (Suite, Double, Single)
			string type;

			cout << setw(40) << "Type  " << endl;
			cout << setw(40) << "(S-Single, D-Double, U-Suite) :";

			do
			{
				cin >> type;

				if (cin.fail() || !(type == "S" || type == "s" || type == "D" || type == "d"
					|| type == "U" || type == "u"))
				{
					cout << "Invalid entry for room type. Try Again.\n";
					cout << setw(40) << "(S-Single, D-Double, U-Suite) :";
				}
			} while (!(type == "S" || type == "s" || type == "D" || type == "d"
				|| type == "U" || type == "u"));

			// Call function to set type for room object
			rm.setRoomType(type);

			//Input room status
			string stat;

			cout << setw(40) << "Status  " << endl;
			cout << setw(40) << "(A-Available, R-Reserved, O-Occupied) :";

			do
			{
				cin >> stat;

				if (cin.fail() || !(stat == "A" || stat == "a" || stat == "R" || stat == "r"
					|| stat == "O" || stat == "o"))
				{
					cout << "Invalid entry for room status. Try Again.\n";
					cout << setw(40) << "(A-Available, R-Reserved, O-Occupied) :";
				}
			} while (!(stat == "A" || stat == "a" || stat == "R" || stat == "r"
				|| stat == "O" || stat == "o"));
			// Call function to set status for room object
			rm.setRoomStatus(stat);

			// Input Room rate
			int price;

			cout << setw(40) << "Rate  " << endl;
			cout << setw(40) << "(199, 101, 268) :";

			do
			{
				cin >> price;

				if (cin.fail() || (price != 199 && price != 101 && price != 268))
				{
					cout << "Invalid Price. Try Again.\n";
					cout << setw(40) << "(199, 101, 268) :";
				}
			} while (price != 199 && price != 101 && price != 268);

			// function to set room rate
			rm.setRoomRate(price);

			// Add room to room vector object
			ht.addRoom(rm);
			break;
		} // Close case I


		case 'R':
		case 'r':
		{
			ht.sortRooms();          // Sort rooms by room number
			ht.displayRoomsList();   // Print hotel info + room table
			break;
		}



		case 'E':
		case 'e':
			cout << "Exiting...\n";
			break;

		default:
			cout << "Invalid selection. Program Ends. \n";
			break;
		} // close switch

		// Wait before showing menu again
		pauseUntilUserIsReady();
		clearCin();
	} while (choice != 'E' && choice != 'e');
} // close managerMenu
// Briceno-Dav-Lab7.cpp -- Clinic Staff Report Program. Allows user to input clinic general
//                          information, doctor information and nurses' information according
//                          to given restrictions.
// CSIS 112 B01 202630

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cstring>
#include "Clinic.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Date.h"

using namespace std;

// function prototypes
void clearCin();
void pauseUntilUserIsReady();
bool tokenizeDate(char charDate[], int& month, int& day, int& year);
bool validDate(int month, int day, int year);

int main()
// Purpose of this program is to demonstrate the ability to overload operators, use inheritance
// and composition to create a Clinic Informational/Personnel report.
{
    cout << "David Briceno - Assignment 7 - Inheritance / Operator Overloading" << endl << endl;

    cout << setw(38) << left << "Enter Clinic Information:" << endl << endl;

    Clinic clinic;

    string clinicName;
    string clinicCity;
    string clinicState;
    char openedDate[20];
    int m, d, y;

    cout << right;

    // Clinic Name (letters only)
    while (true)
    {
        cout << setw(39) << "Clinic Name: ";
        getline(cin, clinicName);

        if (clinicName.empty())
        {
            cout << "Invalid value. A blank entry was received." << endl;
            continue;
        }

        bool bad = false;
        for (char c : clinicName)
        {
            if (!isalpha(c) && c != ' ')
            {
                bad = true;
                break;
            }
        }

        if (bad)
        {
            cout << "Invalid value. Only alphabetic characters are allowed." << endl;
            continue;
        }

        break;
    }
    clinic.setName(clinicName);

    // Opened for Business date
    while (true)
    {
        cout << setw(39) << "Opened for Business (mm/dd/yyyy): ";
        cin >> openedDate;
        clearCin();

        if (!tokenizeDate(openedDate, m, d, y))
        {
            cout << "Invalid value. Date must be entered as mm/dd/yyyy." << endl;
            continue;
        }

        if (!validDate(m, d, y))
            continue;

        break;
    }
    Date opened;
    opened.setDate(m, d, y);
    clinic.setOpenedForBusiness(opened);

    // Clinic City (letters only)
    while (true)
    {
        cout << setw(39) << "Clinic City: ";
        getline(cin, clinicCity);

        if (clinicCity.empty())
        {
            cout << "Invalid value. A blank entry was received." << endl;
            continue;
        }

        bool bad = false;
        for (char c : clinicCity)
        {
            if (!isalpha(c) && c != ' ')
            {
                bad = true;
                break;
            }
        }

        if (bad)
        {
            cout << "Invalid value. Only alphabetic characters are allowed." << endl;
            continue;
        }

        break;
    }
    clinic.setCity(clinicCity);

    // Clinic State (letters only)
    while (true)
    {
        cout << setw(39) << "State: ";
        getline(cin, clinicState);

        if (clinicState.empty())
        {
            cout << "Invalid value. A blank entry was received." << endl;
            continue;
        }

        bool bad = false;
        for (char c : clinicState)
        {
            if (!isalpha(c) && c != ' ')
            {
                bad = true;
                break;
            }
        }

        if (bad)
        {
            cout << "Invalid value. Only alphabetic characters are allowed." << endl;
            continue;
        }

        break;
    }
    clinic.setState(clinicState);

    pauseUntilUserIsReady();

    char menuChoice = ' ';

    do
    {
        cout << endl;
        cout << "Main Menu:" << endl << endl;
        cout << "D - Doctor Information" << endl;
        cout << "N - Nurse Information (min 3 - max 5)" << endl;
        cout << "L - List the Clinic Information" << endl;
        cout << "X - Exit" << endl << endl;
        cout << "Selection: ";

        cin >> menuChoice;
        cout << endl;
        clearCin();

        // reject invalid menu choices
        if (menuChoice != 'D' && menuChoice != 'd' &&
            menuChoice != 'N' && menuChoice != 'n' &&
            menuChoice != 'L' && menuChoice != 'l' &&
            menuChoice != 'X' && menuChoice != 'x')
        {
            continue;
        }

        // Doctor Section
        if (menuChoice == 'D' || menuChoice == 'd')
        {
            cout << endl;
            cout << setw(39) << left << "Enter Doctor Information:" << endl << endl;

            string first, last, city, state, title;
            char birthDate[20];
            char ownershipDate[20];
            string compInput;
            double compensation;

            cout << right;

            // First name (letters + punctuation)
            while (true)
            {
                cout << setw(39) << "First name: ";
                getline(cin, first);

                if (first.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : first)
                {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'' && c != '.')
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only alphabetic characters and - ' . are allowed." << endl;
                    continue;
                }

                break;
            }

            // Last name (letters + punctuation)
            while (true)
            {
                cout << setw(39) << "Last name: ";
                getline(cin, last);

                if (last.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : last)
                {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'' && c != '.')
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only alphabetic characters and - ' . are allowed." << endl;
                    continue;
                }

                break;
            }

            // Doctor Title (letters + punctuation)
            while (true)
            {
                cout << setw(39) << "Doctor's Title: ";
                getline(cin, title);

                if (title.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : title)
                {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'' && c != '.' && c != ',')
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only alphabetic characters and - ' . , are allowed." << endl;
                    continue;
                }

                break;
            }

            // Birthdate
            while (true)
            {
                cout << setw(39) << "Birthdate (mm/dd/yyyy): ";
                cin >> birthDate;
                clearCin();

                if (!tokenizeDate(birthDate, m, d, y))
                {
                    cout << "Invalid value. Date must be entered as mm/dd/yyyy." << endl;
                    continue;
                }

                if (!validDate(m, d, y))
                    continue;

                break;
            }
            Date birth;
            birth.setDate(m, d, y);

            // Ownership date
            while (true)
            {
                cout << setw(39) << "Ownership Established (mm/dd/yyyy): ";
                cin >> ownershipDate;
                clearCin();

                if (!tokenizeDate(ownershipDate, m, d, y))
                {
                    cout << "Invalid value. Date must be entered as mm/dd/yyyy." << endl;
                    continue;
                }

                if (!validDate(m, d, y))
                    continue;

                break;
            }
            Date ownership;
            ownership.setDate(m, d, y);

            // Compensation (numbers only)
            while (true)
            {
                cout << setw(39) << "Compensation Package Value: ";
                getline(cin, compInput);

                if (compInput.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : compInput)
                {
                    if (!isdigit(c))
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only numeric characters are allowed." << endl;
                    continue;
                }

                break;
            }
            compensation = stod(compInput);

            // City (letters + punctuation)
            while (true)
            {
                cout << setw(39) << "City: ";
                getline(cin, city);

                if (city.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : city)
                {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'' && c != '.')
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only alphabetic characters and - ' . are allowed." << endl;
                    continue;
                }

                break;
            }

            // State (letters + punctuation)
            while (true)
            {
                cout << setw(39) << "State: ";
                getline(cin, state);

                if (state.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : state)
                {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'' && c != '.')
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only alphabetic characters and - ' . are allowed." << endl;
                    continue;
                }

                break;
            }

            Doctor doc(first, last, city, state, birth, title, compensation, ownership);
            clinic.setDoctor(doc);

            cout << endl;
            pauseUntilUserIsReady();

        }
        // Nurse Section
        else if (menuChoice == 'N' || menuChoice == 'n')
        {
            cout << endl;
            cout << setw(38) << left << "Enter Nurse Information:" << endl << endl;

            string first, last, city, state, specialty, position;
            char birthDate[20];
            char hiredDate[20];
            string salaryInput;
            double salary;
            int m, d, y;

            cout << right;

            // First name (letters + punctuation)
            while (true)
            {
                cout << setw(39) << "First name: ";
                getline(cin, first);

                if (first.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : first)
                {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'' && c != '.')
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only alphabetic characters and - ' . are allowed." << endl;
                    continue;
                }

                break;
            }

            // Last name (letters + punctuation)
            while (true)
            {
                cout << setw(39) << "Last name: ";
                getline(cin, last);

                if (last.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : last)
                {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'' && c != '.')
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only alphabetic characters and - ' . are allowed." << endl;
                    continue;
                }

                break;
            }

            // Specialty (letters + punctuation)
            while (true)
            {
                cout << setw(39) << "Specialty (Kids, Seniors, etc.): ";
                getline(cin, specialty);

                if (specialty.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : specialty)
                {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'' && c != '.' && c != ',')
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only alphabetic characters and - ' . , are allowed." << endl;
                    continue;
                }

                break;
            }

            // Position (letters + punctuation)
            while (true)
            {
                cout << setw(39) << "Position (Educator, Home Visit, etc.): ";
                getline(cin, position);

                if (position.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : position)
                {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'' && c != '.' && c != ',')
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only alphabetic characters and - ' . , are allowed." << endl;
                    continue;
                }

                break;
            }

            // Salary (numbers only)
            while (true)
            {
                cout << setw(39) << "Annual Salary: ";
                getline(cin, salaryInput);

                if (salaryInput.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : salaryInput)
                {
                    if (!isdigit(c))
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only numeric characters are allowed." << endl;
                    continue;
                }

                break;
            }
            salary = stod(salaryInput);

            // Hire date
            while (true)
            {
                cout << setw(39) << "Hire Date (mm/dd/yyyy): ";
                cin >> hiredDate;
                clearCin();

                if (!tokenizeDate(hiredDate, m, d, y))
                {
                    cout << "Invalid value. Date must be entered as mm/dd/yyyy." << endl;
                    continue;
                }

                if (!validDate(m, d, y))
                    continue;

                break;
            }
            Date hired;
            hired.setDate(m, d, y);

            // City (letters + punctuation)
            while (true)
            {
                cout << setw(39) << "City: ";
                getline(cin, city);

                if (city.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : city)
                {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'' && c != '.')
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only alphabetic characters and - ' . are allowed." << endl;
                    continue;
                }

                break;
            }

            // State (letters + punctuation)
            while (true)
            {
                cout << setw(39) << "State: ";
                getline(cin, state);

                if (state.empty())
                {
                    cout << "Invalid value. A blank entry was received." << endl;
                    continue;
                }

                bool bad = false;
                for (char c : state)
                {
                    if (!isalpha(c) && c != ' ' && c != '-' && c != '\'' && c != '.')
                    {
                        bad = true;
                        break;
                    }
                }

                if (bad)
                {
                    cout << "Invalid value. Only alphabetic characters and - ' . are allowed." << endl;
                    continue;
                }

                break;
            }

            // Birthdate
            while (true)
            {
                cout << setw(39) << "Birthdate (mm/dd/yyyy): ";
                cin >> birthDate;
                clearCin();

                if (!tokenizeDate(birthDate, m, d, y))
                {
                    cout << "Invalid value. Date must be entered as mm/dd/yyyy." << endl;
                    continue;
                }

                if (!validDate(m, d, y))
                    continue;

                break;
            }
            Date birth;
            birth.setDate(m, d, y);

            // Prevent more than 5 nurses
            if (clinic.numberNurses() >= 5)
            {
                cout << "Maximum number of nurses (5) has already been reached." << endl;
                pauseUntilUserIsReady();
                continue;
            }

            Nurse nurse(first, last, city, state, birth, specialty, salary, position, hired);
            clinic.addNurse(nurse);

            cout << endl;
            pauseUntilUserIsReady();

            }

            // List Clinic Info
        else if (menuChoice == 'L' || menuChoice == 'l')
        {
            clinic.sortNurses();

            cout << endl;

            // Clinic header formatted to specifications
            cout << setfill(' ');
            cout << setw(23) << setfill(' ') << right << "Clinic Name: " << clinic.getName() << endl;
            cout << setw(23) << setfill(' ') << right << "Clinic Location: " << clinic.getCity() << ", " << clinic.getState() << endl;
            cout << setw(23) << setfill(' ') << right << "Opened For Business: " << clinic.getOpenedForBusiness() << endl << endl;

            cout << left << "Doctor:" << endl << endl;
            Doctor d = clinic.getDoctor();
            cout << d.createFullName() << " - " << d.getTitle() << endl;    // Combine name and list position
            cout << setw(23) << setfill(' ') << right << "Lives in: " << d.getCity() << ", " << d.getState() << endl;
            cout << setw(23) << setfill(' ') << right << "Birthdate: " << d.getBirthDate() << endl;
            cout << setw(23) << setfill(' ') << right << "Ownership Date: " << d.getOwnershipEstablished() << endl;
            cout << setw(23) << setfill(' ') << right << "Compensation: " << d.getValueCompensationPackage() << endl << endl <<endl;

            cout << left << "Nurses:" << endl << endl;

            for (const Nurse& n : clinic.getNurses())
            {
                cout << n.createFullName() << " - " << n.getPosition() << endl;     // Combine name and list position
                cout << setw(23) << setfill(' ') << right << "Lives in: " << n.getCity() << ", " << n.getState() << endl;
                cout << setw(23) << setfill(' ') << right << "Specialty: " << n.getSpecialty() << endl;
                cout << setw(23) << setfill(' ') << right << "Annual salary_Nurse: " << n.getSalary() << endl;
                cout << setw(23) << setfill(' ') << right << "Date Hired: " << n.getDateHired() << endl;
                cout << setw(23) << setfill(' ') << right << "Birthdate: " << n.getBirthDate() << endl << endl;
            }

            pauseUntilUserIsReady();
            }

            // Exit
        else if (menuChoice == 'X' || menuChoice == 'x')
        {
            int count = clinic.numberNurses();

            if (count < 3)      // Validate to meet min requirement for nurses
            {
                cout << "More nurses are required before exiting (minimum 3)." << endl;
                pauseUntilUserIsReady();
                menuChoice = ' ';
            }
            else if (count > 5)     // Validate if too many nurses are added (even though guardrails are present in Nurse section)
            {
                cout << "Too many nurses entered (maximum 5). Please remove extras." << endl;
                pauseUntilUserIsReady();
                menuChoice = ' ';
            }
            else
            {
                cout << "Exiting program..." << endl;   // Allows exit when all requirements are met
            }
}


    } while (menuChoice != 'X' && menuChoice != 'x');

    return 0;
}

// clears input buffer
void clearCin()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// pauses until user presses Enter
void pauseUntilUserIsReady()
{
    cout << endl << "Press ENTER to continue...";
    clearCin();
    cin.get();
}

// safely tokenizes a date string into month/day/year using strtok_s
bool tokenizeDate(char charDate[], int& month, int& day, int& year)
{
    char* context = nullptr;

    char* token = strtok_s(charDate, "/", &context);
    if (token == nullptr || strlen(token) == 0)
        return false;
    month = atoi(token);

    token = strtok_s(nullptr, "/", &context);
    if (token == nullptr || strlen(token) == 0)
        return false;
    day = atoi(token);

    token = strtok_s(nullptr, "/", &context);
    if (token == nullptr || strlen(token) == 0)
        return false;
    year = atoi(token);

    return true;
}

// validates date ranges
bool validDate(int month, int day, int year)
{
    bool ok = true;

    if (month < 1 || month > 12)
    {
        cout << "Invalid value. Month must be between 1 and 12." << endl;
        ok = false;
    }

    if (day < 1 || day > 31)
    {
        cout << "Invalid value. Day must be between 1 and 31." << endl;
        ok = false;
    }

    if (year < 1900 || year > 2099)
    {
        cout << "Invalid value. Year must be between 1900 and 2099." << endl;
        ok = false;
    }

    return ok;
}

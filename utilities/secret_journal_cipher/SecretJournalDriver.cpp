// Briceno-Dav-Lab 5.cpp : This program creates a secret journal that can encrypt or decrypt text files
//CSIS 112 B01 202630

  
//<Sources if necessary>
// Professor Williams' Code Snippets
// Class Textbook
// https://cppscripts.com/cpp-strtok_s

//Include statements 
#include <iostream> 
#include <string> 
#include <cstdio>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <limits>
#include "ProcessJournal.h"

using namespace std;


//Global declarations: Constants and type definitions only -- no variables

//Function prototypes 
void clearCin();
void pauseUntilUserIsReady();
char displayMenu();
bool isKeyValid(const string& k);
string trimSpaces(const string& s);
string stripQuotesAndTrim(const string& s);



// The purpose of this assignment is to demonstrate the ability to create and use pointer variables
// and encryption/decryption with a provided Vigenere cipher.
int main()
{
	//In cout statement below SUBSTITUTE your name and lab number
	cout << "David Briceno - Lab 5" << endl << endl;
	
	//Variable declarations
	string userKey;

	//Program logic

    // Get and validate secret key before generating menu
    while (true) {
        cout << "Key for Encryption/Decryption: ";
        getline(cin, userKey);

        // Trim leading/trailing spaces and common invisible chars
        userKey = trimSpaces(userKey);

        // Forbid 0 as a key entry
        if (userKey == "0") {
            cout << "Key can not be 0. A key of 0 would cause a division by zero in the cipher. Try again.\n";
            continue;
        }


        if (!isKeyValid(userKey))
        {
            cout << "Invalid key. A key must be non-blank and contain only alphabetic characters.\n";
            continue;
        }
        break;
    }


    // Create the journal with validated key
    ProcessJournal journal(userKey);

    bool running = true;
    while (running) {
        char sel = displayMenu();
        switch (sel) 
        {
        case 'E': {
            // Encryption process
            string inputPath;
            cout << "Name of file to load: ";
            getline(cin, inputPath);
            inputPath = stripQuotesAndTrim(inputPath); // Trim quotes for pasted file paths if needed
            if (inputPath.empty()) 
            {
                cout << "Invalid value. A blank entry was received.\n";
                pauseUntilUserIsReady();
                break;
            }

            // Read file into a string using only getline
            ifstream inFile(inputPath);
            if (!inFile) {
                cout << "Unable to open input file. Returning to menu.\n";
                pauseUntilUserIsReady();
                break;
            }

            string fileContents;
            string line;
            bool firstLine = true;
            while (getline(inFile, line)) 
            {
                if (!firstLine) fileContents += '\n';
                fileContents += line;
                firstLine = false;
            }
            inFile.close();

            // check for empty file
            if (fileContents.length() == 0) {
                cout << "Unable to open input file or file is empty. Returning to menu.\n";
                pauseUntilUserIsReady();
                break;
            }

            // Display loaded text and pause
            cout << "\nThe contents of the file are:\n\n\n" << fileContents << "\n";
            pauseUntilUserIsReady();

            // Copy into char buffer[1000] and tokenize with strtok_s
            char buffer[1000];
            for (int i = 0; i < 1000; ++i) 
                buffer[i] = '\0';
            int maxCopy = 999;
            int toCopy = static_cast<int>(fileContents.length());
            if (toCopy > maxCopy) 
                toCopy = maxCopy;
            for (int i = 0; i < toCopy; ++i) 
                buffer[i] = fileContents[i];
            buffer[toCopy] = '\0';

            journal.clearJournal();
            journal.processEntry(true, buffer); // true = encrypt

            string outPath;
            cout << "Name of Encrypted Journal output file: ";
            getline(cin, outPath);
            if (outPath.empty()) {
                cout << "Invalid value. A blank entry was received.\n";
                pauseUntilUserIsReady();
                break;
            }

            journal.saveJournalFile(outPath);
            cout << "The encrypted journal is saved.\n\n\n";
            cout << "The encrypted text is:\n\n";
            journal.displayJournal();
            cout << "\nWords in encrypted journal: " << journal.determineWordCount() << "\n\n";
            pauseUntilUserIsReady();
            break;
        }

        case 'D': {
            // Decryption process
            string inputPath;
            cout << "Name of Encrypted Journal file to load: ";
            getline(cin, inputPath);
            inputPath = stripQuotesAndTrim(inputPath); // Trim quotes for pasted file paths if needed

            if (inputPath.empty()) {
                cout << "Invalid value. A blank entry was received.\n";
                pauseUntilUserIsReady();
                break;
            }

            ifstream inFile(inputPath);
            if (!inFile) 
            {
                cout << "Unable to open input file. Returning to menu.\n";
                pauseUntilUserIsReady();
                break;
            }

            string fileContents;
            string line;
            bool firstLine = true;
            while (getline(inFile, line)) 
            {
                if (!firstLine) fileContents += '\n';
                fileContents += line;
                firstLine = false;
            }
            inFile.close();

            // check for empty file
            if (fileContents.length() == 0) 
            {
                cout << "Unable to open input file or file is empty. Returning to menu.\n";
                pauseUntilUserIsReady();
                break;
            }

            // Display loaded text and pause
            cout << "\nThe contents of the file are:\n\n\n" << fileContents << "\n\n";
            pauseUntilUserIsReady();

            char buffer[1000];
            for (int i = 0; i < 1000; ++i) buffer[i] = '\0';
            int maxCopy = 999;
            int toCopy = static_cast<int>(fileContents.length());
            if (toCopy > maxCopy) toCopy = maxCopy;
            for (int i = 0; i < toCopy; ++i) buffer[i] = fileContents[i];
            buffer[toCopy] = '\0';

            journal.clearJournal();
            journal.processEntry(false, buffer); // false = decrypt

            string outPath;
            cout << "Name of Decrypted Journal output file: ";  //User enters full filepath/name for output file
            getline(cin, outPath);
            if (outPath.empty()) {
                cout << "Invalid value. A blank entry was received.\n";
                pauseUntilUserIsReady();
                break;
            }

            journal.saveJournalFile(outPath);   // Save decrypted text in output file
            cout << "The decrypted text is:\n\n";
            journal.displayJournal();
            cout << "\n\nWord count: " << journal.determineWordCount() << "\n\n\n";
            pauseUntilUserIsReady();
            break;
        }

        case 'C':
           
            running = false;
            break;


        
        default:
            cout << "Invalid value. The selection must be one of the menu options.\n";
            pauseUntilUserIsReady();
            break;
        } // end switch
    } // end while (running) loop

    cout << "Program closing.\n";


	//Closing program statements

	system("pause");
	return 0;
}
//Function definitions
void pauseUntilUserIsReady()
{
	// Purpose: To pause until the user presses Enter.
	// Source: Professor Walter Williams

	cout << endl << "Press ENTER to continue...";
	clearCin(); // Clear any previous input
	cin.get();
	clearCin(); // Clear any user input
} // pauseUntilUserIsReady



void clearCin()
/*
* Purpose: To ensure the cin buffer is cleared, if needed.
* Source: LU Professor
*/

{
	// The call to cin.rdbuf()->in_avail() checks to see
	//  if there is anything in the input buffer.
	//  If there is, then clear the buffer.
	// This call was added when it was noticed that in the
	//  pauseUntilUserIsReady() function usage, some people
	//  would press other keys before pressing Enter.
	//  A call to clearCin() after the cin.get() would
	//  clear the buffer, but if they only pressed Enter,
	//  the call to clearCin() would cause a problem.
	//  So, the check for anything in the buffer was added.
	if (cin.rdbuf()->in_avail() > 0)
	{
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
} // clearCin()


// Function to Display Menu 
char displayMenu()
{
	char choice;
	cout << std::endl;
	cout << right << setw(22) << "Main Menu\n\n";
	cout << right << setw(29) << "E - Encrypt and save\n";
	cout << right << setw(29) << "D - Decrypt and save\n";
	cout << right << setw(26) << "C - Close journal\n";
    cout << endl << endl << left;
	cout << "Option: ";
	cin >> choice;
	cin.ignore(10000, '\n'); // clear rest of line
	if (choice >= 'a' && choice <= 'z')
		choice = static_cast<char>(choice - 'a' + 'A');
	return choice;
}


// Key validation for only alphabetic characters upper or lower case.
// Validate key using only basic character comparisons
bool isKeyValid(const std::string& k)
{
	if (k.empty())
		return false;
	for (int i = 0; i < static_cast<int>(k.length()); ++i) 
	{
		char ch = k[i];
		if (!((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')))
			return false;
	}
	return true;
}

// Trim leading and trailing spaces and carriage returns (basic implementation)
string trimSpaces(const string& s)
{
    int start = 0;
    int end = static_cast<int>(s.length()) - 1;

    // move start forward past leading spaces or carriage returns or tabs
    while (start <= end && (s[start] == ' ' || s[start] == '\r' || s[start] == '\t'))
        ++start;

    // move end backward past trailing spaces or carriage returns or tabs
    while (end >= start && (s[end] == ' ' || s[end] == '\r' || s[end] == '\t'))
        --end;

    if (start > end) return string();

    string out;
    for (int i = start; i <= end; ++i)
        out += s[i];
    return out;
}


// Trim quotes for copy/pasted filepaths
string stripQuotesAndTrim(const string& s)
{
    int start = 0;
    int end = static_cast<int>(s.length()) - 1;
    while (start <= end && (s[start] == ' ' || s[start] == '\r' || s[start] == '\t')) 
        ++start;
    while (end >= start && (s[end] == ' ' || s[end] == '\r' || s[end] == '\t')) 
        --end;

    if (start <= end && s[start] == '"') 
        ++start;
    if (end >= start && s[end] == '"')
        --end;
    if (start > end) return string();

    string out;
    for (int i = start; i <= end; ++i) 
        out += s[i];
    return out;
}

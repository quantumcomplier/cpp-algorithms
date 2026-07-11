#include "MiscCommon.h"
#include <limits>
#include <iostream>
#include <string>

const std::string TRY_AGAIN = "\nPlease try again.";
void clearCin()
/*
Code from LU Professor.
*/
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
} // clearCin()


/*
This block of functions, ltrim(), rtrim(), and trim(),
are used to trim strings.
- ltrim() - trims leading whitespace from the string
- rtrim() - trims trailing whitespace from the string
- trim() - trims leading and trailing whitespace from the string
These functions were found at:
https://www.techiedelight.com/trim-string-cpp-remove-leading-trailing-spaces/
*/


// This constant defines the list of whitespace type
// characters that are removed from a string.
const std::string WHITESPACE = " \n\r\t\f\v";
std::string ltrim(const std::string& s)
{
	size_t start = s.find_first_not_of(WHITESPACE);
		return (start == std::string::npos) ? "" : s.substr(start);
}

std::string rtrim(const std::string& s)
{
	size_t end = s.find_last_not_of(WHITESPACE);
	return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string trim(const std::string& s)
{
	return rtrim(ltrim(s));
}
// End of block of string trim functions.


bool validateRequiredStringEntry(std::string pstrToTest,
	std::string pstrErrorMessage)
	/*
	Validates a string as NOT empty, i.e. at least one non-white space character.
	Displays the error message passed in with the value that is to be checked.
	Code from LU Professor.
	*/
{
	bool isValid = false;
	// Remove any whitespace
	pstrToTest = trim(pstrToTest);
	if (pstrToTest.empty())
	{
		std::cout << pstrErrorMessage << TRY_AGAIN << std::endl;
		isValid = false;
	}
	else
	{
		isValid = true;
	}
	return isValid;
} // validateRequiredStringEntry()

// Function to pause for user
void pauseUntilUserIsReady()
{
	std::cout << "\nPress ENTER to continue...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
}

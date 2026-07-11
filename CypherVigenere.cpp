

#include "CypherVigenere.h"
#include <string>
#include <cctype>
#include <iostream>

// Function to return the current value of related data members
std::string CypherVigenere::getKeySecret()
{
	return keySecret;
}


// Function receives text, makes uppercase and stores it in the related data member
void CypherVigenere::setKey(std::string keyTxt)
{
	if (keyTxt == "" || keyTxt == "0")
	{
		keySecret = ""; // keep cipher silent; main() will validate and report to user
		return;
	}
	keySecret = changeWordToUpperCase(keyTxt);
}

// Function to make text uppercase and return it
std::string CypherVigenere::changeWordToUpperCase(std::string word)
{
	for (int i = 0; i < static_cast<int>(word.length()); ++i) {
		if (word[i] >= 'a' && word[i] <= 'z')
			word[i] = static_cast<char>(word[i] + ('A' - 'a'));
	}
	return word;
}

// Function receives text, uses the given code and the private key, encrypts text and returns
// it.
std::string CypherVigenere::encryptSingleToken(std::string token)
{
	std::string output;
	std::string privateKey = getKeySecret(); //Required to use getter
	for (int i = 0, j = 0; i < static_cast<int>(token.length()); ++i) {
		char c = token[i];
		if (c >= 'a' && c <= 'z')
			c = static_cast<char>(c + ('A' - 'a'));
		else if (c < 'A' || c > 'Z')
			continue;
		output += static_cast<char>((c + privateKey[j] - 2 * 'A') % 26 + 'A');
		j = (j + 1) % static_cast<int>(privateKey.length());
	}
	return output;

} 


// Function to receive text, use given code and private key, decrypts and returns.
std::string CypherVigenere::decryptSingleToken(std::string token)
{
	std::string output;
	std::string privateKey = getKeySecret();

	for (int i = 0, j = 0; i < static_cast<int>(token.length()); ++i) {
		char c = token[i];
		if (c >= 'a' && c <= 'z')
			c = static_cast<char>(c + ('A' - 'a'));
		else if (c < 'A' || c > 'Z')
			continue;
		output += static_cast<char>((c - privateKey[j] + 26) % 26 + 'A');
		j = (j + 1) % static_cast<int>(privateKey.length());
	}

	return output;
}


// Constructor (zero argument) uses setKey() to initialize to ""
CypherVigenere::CypherVigenere()
{
	setKey("");
}

// Constructor single argument that receives key and calls setKey to update value
CypherVigenere::CypherVigenere(std::string key)
{
	setKey(key);	
}


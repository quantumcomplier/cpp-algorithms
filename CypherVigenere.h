#pragma once

#include <string>

// Encapsulates data and processes used to encrypt and decrypt a token
class CypherVigenere
{
private:
	// Stores private key used to encrypt/decrypt
	std::string keySecret;

	// Function to return the current value of related data members
	std::string getKeySecret();

public:
	// Function receives text, makes uppercase and stores it in the related data member
	void setKey(std::string);

	// Function to make text uppercase and return it
	std::string changeWordToUpperCase(std::string);

	// Function receives text, uses the given code and the private key, encrypts text and returns
	// it.
	std::string encryptSingleToken(std::string);

	// Function to receive text, use given code and private key, decrypts and returns.
	std::string decryptSingleToken(std::string);

	// Constructor (zero argument) uses setKey() to initialize to ""
	CypherVigenere();

	// Constructor single argument that receives key and calls setKey to update value
	CypherVigenere(std::string);

};
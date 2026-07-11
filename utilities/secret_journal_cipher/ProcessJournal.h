#pragma once

#include <string>
#include <vector>
#include "CypherVigenere.h"

// This class encapsulates the data and functions for the secret journal.
// Functions will manipulate and control the data.
class ProcessJournal
{
private:
    // Vector stores the list of words in encrypted or decrypted form
    std::vector<std::string> wordsInJournal;

    // Internal CypherVigenere object for encryption/decryption
    CypherVigenere Secret;

public:
    // Zero-argument constructor
    ProcessJournal();

    // Single-argument constructor (receives key)
    ProcessJournal(std::string);

    // Clears the journal vector
    void clearJournal();

    // Adds a token to the vector
    void addJournalEntry(std::string);

    // Encrypts or decrypts a single token
    void processToken(char*, bool);

    // Saves vector contents to a file (one long line)
    void saveJournalFile(std::string);

    // Displays vector contents on screen (one long line)
    void displayJournal();

    // Returns number of words in the vector
    int determineWordCount();

    // Tokenizes a char* entry and processes each token
    void processEntry(bool, char*);
};

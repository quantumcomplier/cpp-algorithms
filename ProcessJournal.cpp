#include <string>
#include <vector>
#include <cstring>
#include <fstream>
#include <iostream>
#include "CypherVigenere.h"
#include "ProcessJournal.h"



// Zero-argument constructor
ProcessJournal::ProcessJournal()
{
    Secret.setKey("");
}

// Single-argument constructor (receives key)
ProcessJournal::ProcessJournal(std::string key)
{
    Secret.setKey(key);
}

// Clears the journal vector
void ProcessJournal::clearJournal()
{
    wordsInJournal.clear();
}


// Adds a token to the vector
void ProcessJournal::addJournalEntry(std::string word)
{
	wordsInJournal.push_back(word);
}

// Encrypts or decrypts a single token
void ProcessJournal::processToken(char* token, bool encrypt)
{
    std::string result;
    std::string tokenStr(token); // conversion to string

    if (encrypt)
        result = Secret.encryptSingleToken(tokenStr);
    else
        result = Secret.decryptSingleToken(tokenStr);

    addJournalEntry(result);
}


// Saves vector contents to a file (one long line)
void ProcessJournal::saveJournalFile(std::string filePathAndName)
{
    std::ofstream outFile;      // Create ofstream variable

    outFile.open(filePathAndName);   // Open the file to use

    if (!wordsInJournal.empty()) 
    {
        // Output first word, then loop to print a space and the next 
        // word according to vector size.
        outFile << wordsInJournal[0];
        int count = static_cast<int>(wordsInJournal.size());
        for (int i = 1; i < count; ++i)
            outFile << ' ' << wordsInJournal[i];
    }

    outFile.close();
}

// Displays vector contents on screen (one long line)
void ProcessJournal::displayJournal()
{
    if (!wordsInJournal.empty()) {
        std::cout << wordsInJournal[0];
        int count = static_cast<int>(wordsInJournal.size());
        for (int i = 1; i < count; ++i)
            std::cout << ' ' << wordsInJournal[i];
    }
    std::cout << std::endl;
}


// Returns number of words in the vector
int ProcessJournal::determineWordCount()
{
    return static_cast<int>(wordsInJournal.size());
}

// Tokenizes a char* entry and processes each token
void ProcessJournal::processEntry(bool encrypt, char* text)
{
    char* nextToken = nullptr;
    char* token = strtok_s(text, " ", &nextToken);

    while (token != nullptr)
    {
        processToken(token, encrypt);
        token = strtok_s(nullptr, " ", &nextToken);
    }
    

}
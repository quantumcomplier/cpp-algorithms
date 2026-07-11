#pragma once

#include <iostream>
#include <limits>

void clearCin();
// This function ensures that the cin buffer is completely clear
// before the next input starts.

std::string ltrim(const std::string&);
std::string rtrim(const std::string&);
std::string trim(const std::string&);
// These functions allow you to trim a string (remove whitespace)
// variable in C++.

bool validateRequiredStringEntry(std::string, std::string);
// Checks a string parameter to ensure it is not blank

void pauseUntilUserIsReady();

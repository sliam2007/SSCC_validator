// SSCC_validator.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

struct ValidationResult
{
	bool valid;
	std::string error;
};

class SsccValidator
{
public: 
	ValidationResult validate(std::string_view code) const;

private:
	int calculateCheckDigit(std::string_view digits) const;
};
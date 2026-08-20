#include "SsccValidator.h"
#include <algorithm>
#include <cctype>
#include <string>

constexpr std::size_t ExpectedLength = 20;
constexpr std::string_view ExpectedCompanyPrefix = "34260311";
constexpr std::string_view ExpectedAi = "00";

ValidationResult SsccValidator::validate(std::string_view code) const
{
	// length validation
	auto actualLength = code.size();
	if (actualLength != ExpectedLength)
		return { false, "Invalid length: expected "
			+ std::to_string(ExpectedLength)
			+ " characters, got "
			+ std::to_string(actualLength) };

	// digits validation
	if (!std::all_of(code.begin(), code.end(),
		[](unsigned char c) { return std::isdigit(c); }))
		return { false, "Invalid format: only digits are allowed." };

	// AI validation
	auto actualAi = code.substr(0, 2);
	if (actualAi != ExpectedAi)
		return { false, "Invalid AI: expected "
			+ std::string(ExpectedAi)
			+ ", got " 
			+ std::string(actualAi) };

	// Company Prefix validation
	auto actualCompanyPrefix = code.substr(3, 8);
	if (actualCompanyPrefix != ExpectedCompanyPrefix)
		return { false, "Invalid company prefix: expected " 
			+ std::string(ExpectedCompanyPrefix) 
			+ ", got "
			+ std::string(actualCompanyPrefix) };

	// Check digit validation
	int expectedCheckDigit = calculateCheckDigit(code.substr(2, 17));
	int actualCheckDigit = code[19] - '0';
	
	if (expectedCheckDigit != actualCheckDigit)
		return { false, "Invalid check digit: expected " +
			std::to_string(expectedCheckDigit) + 
			", got " +
			std::to_string(actualCheckDigit)
		};

	return { true, "" };
}

int SsccValidator::calculateCheckDigit(std::string_view digits) const
{
	int sum = 0;
	for (std::size_t i = 0; i < digits.size(); i++)
	{
		int digit = digits[i] - '0';
		int weight = (i % 2 == 0) ? 3 : 1;

		sum += digit * weight;
	}

	return (10 - (sum % 10)) % 10;
}
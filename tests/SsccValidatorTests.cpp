#include "../SsccValidator.h"

#include <iostream>

int main()
{
	SsccValidator validator;

	// valid SSCC code
	auto result = validator.validate("00034260311130776594");

	if (!result.valid)
	{
		std::cout << "Valid SSCC test failed" << std::endl;
		return 1;
	}

	std::cout << "Valid SSCC test passed" << std::endl;

	// invalid AI
	auto invalidResult = validator.validate("02044260311130776512");

	if (invalidResult.valid)
	{
		std::cout << "Invalid AI test failed" << std::endl;
		return 1;
	}

	std::cout << "Invalid AI test passed" << std::endl;

	// invalid check digit 
	auto invalidCheckDigitResult = validator.validate("00034260311130776144");

	if (invalidCheckDigitResult.valid)
	{
		std::cout << "Invalid check digit test failed" << std::endl;
		return 1;
	}

	std::cout << "Invalid check digit test passed" << std::endl;

	// second valid SSCC code
	auto validSecondSsccResult = validator.validate("00034260311130776570");
	
	if (!validSecondSsccResult.valid)
	{
		std::cout << "Second valid SSCC test failed" << std::endl;
		return 1;
	}

	std::cout << "Second valid SSCC test passed" << std::endl;

	// invalid length
	auto invalidLengthResult = validator.validate("0003426031113077646");

	if (invalidLengthResult.valid)
	{
		std::cout << "Invalid length test failed" << std::endl;
		return 1;
	}

	std::cout << "Invalid length test passed" << std::endl;

	// invalid company prefix
	auto invalidCompanyPrefixResult = validator.validate("00034260321130774636");

	if (invalidCompanyPrefixResult.valid)
	{
		std::cout << "Invalid company prefix test failed" << std::endl;
		return 1;
	}

	std::cout << "Invalid company prefix test passed" << std::endl;

	// non-digit code
	auto nonDigitResult = validator.validate("000342603111307765v4");

	if (nonDigitResult.valid)
	{
		std::cout << "Non-digit character test failed" << std::endl;
		return 1;
	}

	std::cout << "Non-digit character test passed" << std::endl;

	return 0;
}
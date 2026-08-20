#include "SsccValidator.h"

#include <array>
#include <string>

using namespace std;

int main()
{
	cout << "SSCC Validator" << endl;
	cout << endl;

	array<string, 6> examples = {
		"00034260311130776594",
		"02044260311130776512",
		"00034260311130776144",
		"00034260311130776570",
		"0003426031113077646",
 		"00034260321130774636"
	};

	SsccValidator validator;

	cout << "Provided examples:" << endl;

	for (const auto& example : examples)
	{
		auto result = validator.validate(example);

		if (result.valid)
			cout << example << " -> VALID" << endl;
		else
			cout << example << " -> INVALID: " << result.error << endl;
	}

	cout << endl;

	string input;

	while (true)
	{
		cout << "Enter SSCC code (or q to quit): ";

		if (!getline(cin, input) || input == "q")
			break;

		auto result = validator.validate(input);

		if (result.valid)
			cout << input << " -> VALID" << endl;
		else
			cout << input << " -> INVALID: " << result.error << endl;

		cout << endl;
	}

	return 0;
}

#include <iostream>

using namespace std;

int main()
{
	string input;
	while (!cin.eof())
	{
		getline(cin, input);

		for (int chIndex = 0; chIndex < input.size(); ++chIndex)
		{
			if (!ispunct(input[chIndex]))
			{
				cout << input[chIndex];
			}
		}

		cout << '\n';
	}

	return 0;
}

#include <iostream>

using namespace std;

void OutputCharClassifications(char ch, ostream& outputStream)
{
	if (isspace(ch))
	{
		outputStream << "Space ";
	}

	if (isalpha(ch))
	{
		outputStream << "Alpha ";
	}

	if (isdigit(ch))
	{
		outputStream << "Digit ";
	}

	if (isxdigit(ch))
	{
		outputStream << "XDigit ";
	}

	if (isupper(ch))
	{
		outputStream << "Upper ";
	}

	if (islower(ch))
	{
		outputStream << "Lower ";
	}

	if (isalnum(ch))
	{
		outputStream << "Alpha-numeric ";
	}

	if (iscntrl(ch))
	{
		outputStream << "Control ";
	}

	if (ispunct(ch))
	{
		outputStream << "Punct ";
	}

	if (isprint(ch))
	{
		outputStream << "Print ";
	}

	if (isgraph(ch))
	{
		outputStream << "Graph ";
	}
}

int main()
{
	string inputLine;

	getline(cin, inputLine);
	
	for (int chIndex = 0; chIndex < inputLine.size(); ++chIndex)
	{
		cout << inputLine[chIndex] << " is\t";

		OutputCharClassifications(inputLine[chIndex], cout);
		cout << '\n';
	}
	
	return 0;
}

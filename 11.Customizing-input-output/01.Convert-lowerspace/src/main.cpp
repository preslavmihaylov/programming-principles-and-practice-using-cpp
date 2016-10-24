#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream inputStream("mixed_case.txt");
	ofstream outputStream("lower_case.txt");
	string inputLine;
	
	if (!inputStream)
	{
		cout << "Cannot open file mixed_case.txt\n";
		return 1;
	}

	if (!outputStream)
	{
		cout << "Cannot open file for writing lower_case.txt\n";
		return 1;
	}

	while (getline(inputStream, inputLine))
	{
		for (int chIndex = 0; chIndex < inputLine.size(); ++chIndex)
		{
			outputStream << (char)tolower(inputLine[chIndex]);
		}
		outputStream << '\n';
	}

	return 0;
}

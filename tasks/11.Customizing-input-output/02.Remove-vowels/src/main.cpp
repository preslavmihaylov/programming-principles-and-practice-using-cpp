#include <iostream>
#include <fstream>

using namespace std;

bool IsVowel(char input)
{
	return (input == 'a') ||
		   (input == 'o') ||
		   (input == 'u') ||
		   (input == 'e') ||
		   (input == 'i') ||
		   (input == 'y');
}

int main()
{
	ifstream inputStream("text_with_vowels.txt");
	ofstream outputStream("text_without_vowels.txt");
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
			if (!IsVowel(inputLine[chIndex]))
			{
				outputStream << inputLine[chIndex];
			}
		}
		outputStream << '\n';
	}

	return 0;
}

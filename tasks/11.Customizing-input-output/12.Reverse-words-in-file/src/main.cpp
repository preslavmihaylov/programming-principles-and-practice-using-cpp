#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cassert>

using namespace std;

int GetFileSize(fstream& fileStream);
void ReverseFileContents(fstream& fileStream, int start, int end);
void ReverseWordsInFile(fstream& fileStream);

void ReverseFileContents(fstream& fileStream, int start, int end)
{
	int endIndex;
	char firstChar;
	char secondChar;

	if (start < 0 || end < 0)
	{
		assert(false);
		exit(1);	
	}

	for (int index = start; index < ((start + end) / 2); ++index)
	{
		endIndex = (end - 1 - index) + start;
		// extract first char
		fileStream.seekg(index);
		fileStream.get(firstChar);

		// extract last char
		fileStream.seekg(endIndex);
		fileStream.get(secondChar);

		// set second char at first char position
		fileStream.seekp(index);
		fileStream.put(secondChar);

		// set first char at second char position
		fileStream.seekp(endIndex);
		fileStream.put(firstChar);
	}
}

void ReverseWordsInFile(fstream& fileStream)
{
	int secondCharIndex;
	char firstChar;
	char secondChar;

	int fileSize = GetFileSize(fileStream);

	int leftWordStart = 0;
	int rightWordEnd = fileSize - 1;

	for (int firstCharIndex = 0; firstCharIndex < (fileSize / 2); ++firstCharIndex)
	{
		// -2 in order to ignore '\n' character
		secondCharIndex = fileSize - 2 - firstCharIndex;
		// extract first char
		fileStream.seekg(firstCharIndex);
		fileStream.get(firstChar);

		// extract last char
		fileStream.seekg(secondCharIndex);
		fileStream.get(secondChar);

		// set second char at first char position
		fileStream.seekp(firstCharIndex);
		fileStream.put(secondChar);

		// set first char at second char position
		fileStream.seekp(secondCharIndex);
		fileStream.put(firstChar);
		
		// Left word is completely swapped. Reverse it.
		if ((firstChar == ' ') && (rightWordEnd != -1))
		{
			ReverseFileContents(fileStream, secondCharIndex + 1, rightWordEnd);
			rightWordEnd = -1; // secondCharIndex; // skip whitespaces
		}
		
		// start of right word encountered.
		if ((firstChar != ' ') && (rightWordEnd == -1))
		{
			rightWordEnd = secondCharIndex + 1;
		}

		// Right word is completely swapped. Reverse it.
		if ((secondChar == ' ') && (leftWordStart != -1))
		{
			ReverseFileContents(fileStream, leftWordStart, firstCharIndex);
			leftWordStart = -1; // skip whitespaces
		}
		
		// start of left word encountered;
		if ((secondChar != ' ') && (leftWordStart == -1))
		{
			leftWordStart = firstCharIndex;
		}
	}

	// Reverse final word leftover after iteration until the middle
	if ((leftWordStart != -1) && (rightWordEnd != -1))
	{
		ReverseFileContents(fileStream, leftWordStart, rightWordEnd);
	}
}

int GetFileSize(fstream& fileStream)
{
	int start = fileStream.tellg();
	int end;
	fileStream.seekg(0, ios::end);
	end = fileStream.tellg();

	fileStream.seekg(start);
	return end - start;
}

int main()
{
	fstream fileStream("words.txt");
	ReverseWordsInFile(fileStream);
	return 0;
}

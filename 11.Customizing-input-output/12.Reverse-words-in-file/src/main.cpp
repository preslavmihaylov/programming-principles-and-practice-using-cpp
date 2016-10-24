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
	int endIndex;
	char firstChar;
	char secondChar;

	int fileSize = GetFileSize(fileStream);

	int leftWordStart = 0;
	int rightWordEnd = fileSize - 1;

	for (int index = 0; index < (fileSize / 2); ++index)
	{
		// -2 in order to ignore '\n' character
		endIndex = fileSize - 2 - index;
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
		fileStream.flush();
		
		// Left word is completely swapped. Reverse it.
		if ((firstChar == ' ') && (rightWordEnd != -1))
		{
			ReverseFileContents(fileStream, endIndex + 1, rightWordEnd);
			fileStream.flush();
			rightWordEnd = endIndex; // skip whitespaces
		}
		else if (leftWordStart == -1)
		{
			//leftWordStart = index;
		}

		// Right word is completely swapped. Reverse it.
		if ((secondChar == ' ') && (leftWordStart != -1))
		{
			ReverseFileContents(fileStream, leftWordStart, index);
			fileStream.flush();
			leftWordStart = index + 1; // skip whitespaces
		}
		else if (rightWordEnd == -1)
		{
			//rightWordEnd = endIndex + 1;
		}
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
	// int fileSize = GetFileSize(fileStream);
	// ReverseFileContents(fileStream, 0, fileSize);

	return 0;
}

#include <iostream>
#include <fstream>

using namespace std;

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
	char firstChar;
	char secondChar;
	fstream fileStream("characters.txt");
	int fileSize = GetFileSize(fileStream);

	for (int index = 0; index < (fileSize / 2); ++index)
	{
		// extract first char
		fileStream.seekg(index);
		fileStream >> firstChar;
		
		// extract last char
		fileStream.seekg(fileSize - 2 - index);
		fileStream >> secondChar;

		// set second char at first char position
		fileStream.seekp(index);
		fileStream << secondChar;

		// set first char at second char position
		fileStream.seekp(fileSize - 2 - index);
		fileStream << firstChar;
	}

	return 0;
}

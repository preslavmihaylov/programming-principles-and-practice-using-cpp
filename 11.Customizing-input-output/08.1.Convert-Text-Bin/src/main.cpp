#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream inputStream("text.txt");
	ofstream outputStream("binary.txt", ios_base::binary);
	string inputLine;
	char ch;

	while (getline(inputStream, inputLine))
	{
		for (int chIndex = 0; chIndex < inputLine.size(); ++chIndex)
		{
			ch = inputLine[chIndex];
			outputStream.write((char*)&ch, sizeof(ch));
		}
	
		ch = '\n';
		outputStream.write((char*)&ch, sizeof(ch));
	}
	
	return 0;
}

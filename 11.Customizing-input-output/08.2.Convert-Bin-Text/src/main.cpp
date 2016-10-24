#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream inputStream("binary.txt", ios_base::binary);
	ofstream outputStream("text.txt");
	string inputLine;
	char ch;

	while (inputStream.read((char *)&ch, sizeof(ch)))
	{
		outputStream << ch;
	}
	
	return 0;
}

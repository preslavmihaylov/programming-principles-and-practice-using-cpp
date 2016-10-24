#include <iostream>
#include <fstream>

using namespace std;

static int spaceCnt = 0;
static int alphaCnt = 0;
static int digitCnt = 0;
static int xdigitCnt = 0;
static int upperCnt = 0;
static int lowerCnt = 0;
static int alnumCnt = 0;
static int cntrlCnt = 0;
static int punctCnt = 0;
static int printCnt = 0;
static int graphCnt = 0;

void GetCharClassifications(char ch)
{
	if (isspace(ch))  { ++spaceCnt; }
	if (isalpha(ch))  { ++alphaCnt; } 
	if (isdigit(ch))  { ++digitCnt; } 
	if (isxdigit(ch)) { ++xdigitCnt; } 
	if (isupper(ch))  { ++upperCnt; } 
	if (islower(ch))  { ++lowerCnt; } 
	if (isalnum(ch))  { ++alnumCnt; } 
	if (iscntrl(ch))  { ++cntrlCnt; } 
	if (ispunct(ch))  { ++punctCnt; } 
	if (isprint(ch))  { ++printCnt; } 
	if (isgraph(ch))  { ++graphCnt; } 
}

void OutputCharClassificationsCount(ostream& outputStream)
{
	cout << "isspace\t\t" << spaceCnt << '\n';
	cout << "isalpha\t\t" << alphaCnt << '\n';
	cout << "isdigit\t\t" << digitCnt << '\n';
	cout << "isxdigit\t" << xdigitCnt << '\n';
	cout << "isupper\t\t" << upperCnt << '\n';
	cout << "islower\t\t" << lowerCnt << '\n';
	cout << "isalnum\t\t" << alnumCnt << '\n';
	cout << "iscntrl\t\t" << cntrlCnt << '\n';
	cout << "ispunct\t\t" << punctCnt << '\n';
	cout << "isprint\t\t" << printCnt << '\n';
	cout << "isgraph\t\t" << graphCnt << '\n';
}

int main()
{
	fstream inputStream("input.txt");
	string inputLine;
	int chIndex;

	while (getline(inputStream, inputLine))
	{
		for (chIndex = 0; chIndex < inputLine.size(); ++chIndex)
		{
			GetCharClassifications(inputLine[chIndex]);
		}
	}
	
	OutputCharClassificationsCount(cout);

	return 0;
}

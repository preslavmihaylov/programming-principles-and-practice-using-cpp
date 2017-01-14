#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

int main()
{
	string pattern = "\\d{1,2}\\/\\d{1,2}\\/(\\d{4}|\\d{2})";
	regex reg(pattern);

	cout << "pattern: " << pattern << endl;

	ifstream in("file.txt");
	if (!in) cerr << "no file\n";

	int lineno = 0;
	string line;
	while (getline(in, line))
	{
		++lineno;
		smatch matches;
		if (regex_search(line, matches, reg))
		{
			cout << lineno << ": " << line << '\n';
		}
	}

	return 0;
}

#include <iostream>
#include <regex>
#include <fstream>
#include <stdexcept>

using namespace std;

int main()
{ 
	string pattern;
	string filename;
	cin >> pattern;
	regex reg;

	try
	{
		reg = pattern;
	}
	catch (regex_error)
	{
		cout << pattern << " is not a valid pattern";
		exit(1);
	}

	cin >> filename;


	ifstream in(filename);
	if (!in) cerr << "error opening " << filename << '\n';
	
	cout << "pattern: " << pattern << endl;

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

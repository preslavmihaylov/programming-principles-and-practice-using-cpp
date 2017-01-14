#include <iostream>
#include <regex>
#include <fstream>

using namespace std;

int main()
{
	string pattern = "\\w{2}\\s*\\d{5}(-\\d{4})?";
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
			cout << lineno << ": " << matches[0] << '\n';
			if (matches.size() > 1 && matches[1].matched)
			{
				cout << ": " << matches[1] << '\n';
			}
		}
	}

	return 0;
}

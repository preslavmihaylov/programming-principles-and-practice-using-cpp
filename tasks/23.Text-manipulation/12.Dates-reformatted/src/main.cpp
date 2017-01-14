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
	ofstream out("output.txt");
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
			string matched = matches[0];
			string day;
			string month;
			string year;
			string::iterator it = matched.begin();

			while (it != matched.end() && *it != '/')
			{
				day += *it;		
				++it;
			}
			
			++it; // skip '/'
			while (it != matched.end() && *it != '/')
			{
				month += *it;		
				++it;
			}

			++it; // skip '/'
			while (it != matched.end() && *it != '/')
			{
				year += *it;		
				++it;
			}
			
			string reformatted = year + '/' + month + '/' + day;
			int startPos = line.find(matched);
			if (startPos != string::npos)
			{
				line.replace(startPos, matched.size(), reformatted);
			}
		}

		out << line << '\n';
	}

	return 0;
}

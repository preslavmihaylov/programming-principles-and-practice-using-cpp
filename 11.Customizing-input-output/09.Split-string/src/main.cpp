#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(const string& input);
vector<string> split(const string& input, const string& delim);

vector<string> split(const string& input)
{
	return split(input, "");
}

vector<string> split(const string& input, const string& delim)
{
	istringstream ss(input);
	vector<string> outputVector;
	string token;
	
	while (ss>>token)
	{
		bool matchesDelim = true;
		for (int delimIndex = 0; delimIndex < delim.size(); ++delimIndex)
		{
			if (token[delimIndex] != delim[delimIndex])
			{
				matchesDelim = false;
				break;
			}
		}

		if (matchesDelim == true)
		{
			token = token.substr(delim.size(), token.size() - delim.size());
		}

		outputVector.push_back(token);
	}

	return outputVector;
}

int main()
{
	string inputLine;
	string delim;
	vector<string> tokens;
	
	cout << "Enter a string to split: ";
	getline(cin, inputLine);
	cout << "Input an additional delimiter: ";
	cin >> delim;

	// tokens = split(inputLine);
	tokens = split(inputLine, delim);

	for (auto token : tokens)
	{
		cout << token << '\n';
	}

	return 0;
}

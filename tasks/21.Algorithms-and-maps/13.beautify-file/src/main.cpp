#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream is("input.txt");
	ofstream os("output.txt");

	string word;
	while (is >> word)
	{
		bool includedAnything = false;
		for (int i = 0; i < word.size(); ++i)
		{
			char ch = word[i];
			
			// uppercase becomes lowercase
			if (ch >= 'A' && ch <= 'Z') ch = (ch - 'A') + 'a';
				
			if (ispunct(ch))
			{
				// do not include punctuation
			}
			else if (ch == 's' && (i == (word.size() - 1)))
			{
				// do not include plurals
			}
			else
			{
				os << ch;
				includedAnything = true;
			}
		}

		if (includedAnything) os << ' ';
	}

	return 0;
}

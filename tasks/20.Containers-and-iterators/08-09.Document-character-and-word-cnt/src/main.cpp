#include <iostream>
#include <vector>
#include <fstream>

#include "document.h"

using namespace std;

void eraseLine(Document& d, int n)
{
	if (n < 0 || n > d.lines.size()) return;
	
	auto linesIter = d.lines.begin();
	advance(linesIter, n);
	d.lines.erase(linesIter);
}

bool match(TextIterator start, TextIterator end, const string& str)
{
	int index = 0;
	while (start != end && (index < str.size()))
	{
		if (*start != str[index++]) return false; 
		++start;
	}

	return true;
}

TextIterator find(TextIterator begin, TextIterator end, char& ch)
{
	while (begin != end)
	{
		if (*begin == ch) break;
		++begin;
	}

	return begin;
}

TextIterator findTxt(TextIterator first, 
					 TextIterator last, 
					 const string& str)
{
	if (str.size() == 0) return last;
	if (first == last) return last;
	char firstChar = str[0];
	while (true)
	{
		TextIterator p = find(first, last, firstChar);
		if (p == last || match(p, last, str)) return p;
	}

	return last;
}

int countCharacters(Document& d)
{
	int cnt = 0;
	for (TextIterator p = d.begin(); p != d.end(); ++p) 
	{
		if (!isspace(*p)) ++cnt;
	}

	return cnt;
}

int countWords(Document& d)
{
	int cnt = 0;
	for (TextIterator p = d.begin(); p != d.end(); ++p) 
	{
		if (isspace(*p)) ++cnt;
	}

	return cnt;
}	

int main()
{
	Document d;
	ifstream f("doc.txt");
	f >> d;
	
	for (TextIterator p = d.begin(); p != d.end(); ++p) cout << *p;	
	
	cout << "Chars Cnt: " << countCharacters(d) << endl;
	cout << "Words Cnt: " << countWords(d) << endl;
	cout << "END" << endl;
	return 0;
}

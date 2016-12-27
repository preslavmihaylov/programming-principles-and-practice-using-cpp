#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <vector>
#include <list>

typedef std::vector<char> Line;

class TextIterator
{
	std::list<Line>::iterator linesIter;
	Line::iterator posIter;
public:
	TextIterator(std::list<Line>::iterator ll, Line::iterator pp)
		: linesIter(ll), posIter(pp) {};

	char& operator*() { return *posIter; }
	TextIterator& operator++()
	{
		++posIter;
		if (posIter == (*linesIter).end())
		{
			++linesIter;
			posIter = (*linesIter).begin();
		}

		return *this;
	}

	bool operator==(const TextIterator& other) const
	{
		return (linesIter == other.linesIter && 
				posIter == other.posIter);
	}

	bool operator!=(const TextIterator& other) const 
	{ 
		return !(*this==other); 
	}
};

struct Document
{
	std::list<Line> lines;
	Document() { lines.push_back(Line()); }

	TextIterator begin() 
	{ 
		return TextIterator(lines.begin(), (*lines.begin()).begin()); 
	}

	TextIterator end()
	{
		std::list<Line>::iterator last = lines.end();
		--last;
		return TextIterator(last, (*last).end());
	}
};

std::istream& operator>>(std::istream& is, Document& d)
{
	is >> std::noskipws;
	
	char ch;
	while (is >> ch)
	{
		d.lines.back().push_back(ch);
		if (ch == '\n') d.lines.push_back(Line());
	}

	is >> std::skipws;
	return is;
}

#endif // DOCUMENT_H

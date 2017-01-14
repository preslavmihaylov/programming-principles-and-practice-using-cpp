#include <fstream>
#include <iostream>
#include "mail_file.h"
using namespace std;

#define MESS_SEPARATOR "----"

Mail_file::Mail_file(const std::string& filename)
{
	ifstream in(filename);

	if (!in)
	{
		cerr << "no " << filename << '\n';
		exit(1);
	}

	string line;
	while (getline(in, line)) this->lines.push_back(line);

	Line_iter start = this->lines.begin();
	for (Line_iter p = this->lines.begin(); p != this->lines.end(); ++p)
	{
		if (*p == MESS_SEPARATOR)
		{
			if (start != p)
			{
				this->m.push_back(Message(start, p));
			}

			start = p+1;
		}
	}
}

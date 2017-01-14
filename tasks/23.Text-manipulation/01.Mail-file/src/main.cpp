#include <iostream>
#include <regex>
#include <fstream>
#include <unordered_map>

#include "mail_file.h"

using namespace std;

int is_prefix(const string& s, const string& p)
{
	int n = p.size();
	// make string which is equal to s[0..n)
	if (string(s, 0, n) == p) return n;
	return 0;
}

bool find_from_addr(const Message* m, string& s)
{
	int n;
	for (Line_iter p = m->begin(); p != m->end(); ++p)
	{
		n = is_prefix(*p, "From: ");
		if (n > 0)
		{
			//make string which is equal to (*p)[n...) 
			s = string(*p, n);
			return true;
		}
	}

	return false;
}

string find_subject(const Message* m)
{
	int n;
	for (Line_iter p = m->begin(); p != m->end(); ++p)
	{
		n = is_prefix(*p, "Subject: ");
		// make string which is equal to (*p)[n...)
		if (n > 0) return string(*p, n);
	}

	return "";
}

int main()
{
	Mail_file mfile("file.txt");
	
	unordered_multimap<string, const Message*> sender;

	for (Mess_iter p = mfile.begin(); p != mfile.end(); ++p)
	{
		const Message& m = *p;
		string s;
		if (find_from_addr(&m, s))
		{
			sender.insert(make_pair(s, &m));
		}
	}

	typedef unordered_multimap<string, const Message*>::const_iterator MCI;
	pair<MCI, MCI> pp = sender.equal_range("John Doe <jdoe@machine.example>");
	for (MCI p = pp.first; p != pp.second; ++p)
	{
		cout << find_subject(p->second) << '\n';
	}
	
	return 0;
}

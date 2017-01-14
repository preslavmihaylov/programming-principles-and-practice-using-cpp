#ifndef MAIL_FILE_H
#define MAIL_FILE_H

#include <vector>
#include <string>

typedef std::vector<std::string>::const_iterator Line_iter;

class Message
{
	Line_iter first;
	Line_iter last;
public: 
	Message(Line_iter p1, Line_iter p2)
		: first(p1), last(p2) {};
	Line_iter begin() const { return this->first; }
	Line_iter end() const { return this->last; }
};

typedef std::vector<Message>::const_iterator Mess_iter;

struct Mail_file
{
	std::string name;
	std::vector<std::string> lines;
	std::vector<Message> m;

	Mail_file(const std::string& filename);

	Mess_iter begin() const { return m.begin(); }
	Mess_iter end() const { return m.end(); }
};

#endif // MAIL_FILE_H

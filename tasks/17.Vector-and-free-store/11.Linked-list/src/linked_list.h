#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

class Link
{
public:
	Link(const std::string& v, Link* p = NULL, Link* n = NULL)
		: value(v), prev(p), next(n) {};

	Link* insert(Link* n);
	Link* add(Link* n);
	Link* find(const std::string& val);
	Link* erase();
	Link* advance(int n);

	void setNext(Link* l) { this->next = l; }
	void setPrev(Link* l) { this->prev = l; }
	void setValue(const std::string& str) { this->value = str; }
	
	Link* getPrev() const { return this->prev; }
	Link* getNext() const { return this->next; }
	std::string getValue() const { return this->value; }
private:
	std::string value;
	Link* prev;
	Link* next;
};

#endif // LINKED_LIST_H

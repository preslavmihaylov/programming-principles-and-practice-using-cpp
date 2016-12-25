#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>

template<class T>
class Link
{
public:
	Link(const T& v, Link* p = NULL, Link* n = NULL)
		: value(v), prev(p), next(n) {};

	Link<T>* insert(Link<T>* n);
	Link<T>* add(Link<T>* n);
	Link<T>* find(const T& val);
	Link<T>* erase();
	Link<T>* advance(int n);

	void setNext(Link<T>* l) { this->next = l; }
	void setPrev(Link<T>* l) { this->prev = l; }
	void setValue(const T& str) { this->value = str; }
	
	Link<T>* getPrev() const { return this->prev; }
	Link<T>* getNext() const { return this->next; }
	T getValue() const { return this->value; }
private:
	T value;
	Link<T>* prev;
	Link<T>* next;
};

#include "linked_list.tpp"
#endif // LINKED_LIST_H

#include "linked_list.h"

Link* Link::insert(Link* n)
{
	if (!n) return this;

	if (this->prev) 
	{
		this->prev->setNext(n);
	}
	
	n->setPrev(this->prev);
	this->prev = n;
	n->setNext(this);

	return n;
}

Link* Link::add(Link* n)
{
	if (!n) return this;

	if (this->next) 
	{
		this->next->setPrev(n);
	}
	
	n->setNext(this->next);
	this->next = n;
	n->setPrev(this);

	return n;
}

Link* Link::find(const std::string& val)
{
	Link* current = this;
	while (current)
	{
		if (current->getValue() == val) return current;
		current = current->getNext();
	}

	return NULL;
}

Link* Link::erase()
{
	if (this->next) this->next->setPrev(this->prev);
	if (this->prev) this->prev->setNext(this->next);
	return this->next;
}
	
Link* Link::advance(int n)
{
	Link* current = this;

	if (n > 0)
	{
		while (n > 0)
		{
			current = current->getNext();
			if (!current) return NULL;
			--n;
		}
	}
	else if (n < 0)
	{
		while (n < 0)
		{
			current = current->getPrev();
			if (!current) return NULL;
			++n;
		}
	}

	return current;
}

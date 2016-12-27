#include <stdexcept>
#include <cassert>

template<class T>
typename list<T>::iterator list<T>::insert(list<T>::iterator p, 
										   const T& val)
{
	Link<T> * curr = p.curr;
	Link<T> * newNode = new Link<T>(val);

	if (curr == NULL)
	{
		this->first = this->last = newNode;
		return list<T>::iterator(newNode);
	}
	
	if (curr->prev) curr->prev->next = newNode;
	newNode->prev = curr->prev;
	curr->prev = newNode;
	
	newNode->next = curr;

	// change head if needed
	if (curr == this->first) this->first = newNode;
	
	return list<T>::iterator(newNode);
}

template<class T>
typename list<T>::iterator list<T>::erase(list<T>::iterator p)
{
	Link<T> * curr = p.curr;
	if (curr == NULL) return this->end();

	if (curr->prev) curr->prev->next = curr->next;
	if (curr->next) curr->next->prev = curr->prev;
	
	// change head and tail if needed
	if (curr == this->first) this->first = curr->next;
	if (curr == this->last) this->last = curr->prev;
	
	Link<T> * nextNode = curr->next;
	delete curr;

	return list<T>::iterator(nextNode);
}

template<class T>
void list<T>::push_back(const T& val)
{
	Link<T> * newNode = new Link<T>(val);

	if (this->last == NULL)
	{
		// when tail is null, head should be null as well
		assert(this->last == this->first);
		this->first = this->last = newNode;
		return;
	}

	this->last->next = newNode;
	newNode->prev = this->last;
	this->last = newNode;
}

template<class T>
void list<T>::push_front(const T& val)
{
	Link<T> * newNode = new Link<T>(val);

	if (this->first == NULL)
	{
		// when tail is null, head should be null as well
		assert(this->last == this->first);
		this->first = this->last = newNode;
		return;
	}

	this->first->prev = newNode;
	newNode->next = this->first;
	this->first = newNode;
}

template<class T>
void list<T>::pop_front()
{
	if (this->first == NULL)
	{
		// when tail is null, head should be null as well
		assert(this->last == this->first);
		throw std::runtime_error("list is empty");
	}

	// if one element left, modify tail pointer as well
	if (this->first == this->last) this->last = NULL;

	Link<T> * nodeToDel = this->first;
	this->first = this->first->next;
	delete nodeToDel;
}

template<class T>
void list<T>::pop_back()
{
	if (this->last == NULL)
	{
		// when tail is null, head should be null as well
		assert(this->last == this->first);
		throw std::runtime_error("list is empty");
	}

	// if one element left, modify tail pointer as well
	if (this->first == this->last) this->first = NULL;

	Link<T> * nodeToDel = this->last;
	this->last = this->last->prev;
	delete nodeToDel;
}

template<class T>
T& list<T>::front()
{
	if (this->first) return this->first->val;
	throw std::runtime_error("list is empty");
}

template<class T>
T& list<T>::back()
{
	if (this->last) return this->last->val;
	throw std::runtime_error("list is empty");
}

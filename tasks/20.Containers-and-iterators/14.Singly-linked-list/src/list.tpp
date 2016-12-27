#include <stdexcept>
#include <cassert>

template<class T>
typename list<T>::iterator list<T>::erase(list<T>::iterator p)
{
	Link<T> * curr = p.curr;
	if (curr == NULL) return this->end();
	
	Link<T> * next = curr->next;
	if (next)
	{
		curr->val = next->val;
		curr->next = next->next;
		delete next;
	}
	
	return list<T>::iterator(curr);
}

template<class T>
void list<T>::push_front(const T& val)
{
	Link<T> * newNode = new Link<T>(val);

	if (this->first == NULL)
	{
		this->first = newNode;
		return;
	}

	newNode->next = this->first;
	this->first = newNode;
}

template<class T>
void list<T>::pop_front()
{
	if (this->first == NULL)
	{
		throw std::runtime_error("list is empty");
	}

	Link<T> * nodeToDel = this->first;
	this->first = this->first->next;
	delete nodeToDel;
}

template<class T>
T& list<T>::front()
{
	if (this->first) return this->first->val;
	throw std::runtime_error("list is empty");
}

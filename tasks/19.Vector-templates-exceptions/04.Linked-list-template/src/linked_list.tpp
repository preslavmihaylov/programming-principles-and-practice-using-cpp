
template<class T>
Link<T>* Link<T>::insert(Link<T>* n)
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

template<class T>
Link<T>* Link<T>::add(Link<T>* n)
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

template<class T>
Link<T>* Link<T>::find(const T& val)
{
	Link<T>* current = this;
	while (current)
	{
		if (current->getValue() == val) return current;
		current = current->getNext();
	}

	return NULL;
}

template<class T>
Link<T>* Link<T>::erase()
{
	if (this->next) this->next->setPrev(this->prev);
	if (this->prev) this->prev->setNext(this->next);
	return this->next;
}
	
template<class T>
Link<T>* Link<T>::advance(int n)
{
	Link<T>* current = this;

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

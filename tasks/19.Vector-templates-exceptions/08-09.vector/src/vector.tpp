#include "vector.h"
#include <memory>

template<class T, class A>
vector<T, A>::vector(const vector& other) // copy constructor
{
	elements = alloc.allocate(other.getSize());
	for (int i = 0; i < other.getSize(); ++i) 
	{
		alloc.construct(&elements[i], other[i]);
	}

	capacity = size = other.getSize();
}

template<class T, class A>
vector<T,A>& vector<T,A>::operator=(const vector& other) // copy assignment
{
	if (this == &other) return *this;

	// enough space, don't allocate
	if (other.getSize() < capacity) 
	{
		for (int i = 0; i < other.getSize(); ++i) 
		{
			alloc.construct(&elements[i], other[i]);
		}
		
		size = other.getSize();
		return *this;
	}

	std::unique_ptr<T> p(alloc.allocate(other.getSize()));
	
	for (int i = 0; i < other.getSize(); ++i) 
	{
		alloc.construct(&p.get()[i], other[i]);
	}

	alloc.deallocate(elements, capacity);
	elements = p.release();
	
	capacity = size = other.getSize();
	return *this;
}

template<class T, class A>
void vector<T,A>::push_back(T val)
{
	if (capacity == 0) reserve(8);	
	if (size >= capacity) reserve(capacity * 2);
	elements[size++] = val;
}

template<class T, class A>
void vector<T,A>::resize(int newsize, T def)
{
	reserve(newsize);
	
	for (int i = size; i < newsize; ++i) 
	{
		alloc.construct(&elements[i], def);
	}

	for (int i = newsize; i < size; ++i) 
	{
		alloc.destroy(&elements[i]);
	}
	
	size = newsize;
}

template<class T, class A>
void vector<T,A>::reserve(int newalloc)
{
	if (newalloc <= capacity) return;

	T * p = alloc.allocate(newalloc);
	for (int i = 0; i < size; ++i) 
	{
		alloc.construct(&p[i], elements[i]);
		alloc.destroy(&elements[i]);
	}

	alloc.deallocate(elements, capacity);
	elements = p;
	capacity = newalloc;
}

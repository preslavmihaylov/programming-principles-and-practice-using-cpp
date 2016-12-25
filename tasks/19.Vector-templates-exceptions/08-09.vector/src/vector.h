#ifndef VECTOR_H
#define VECTOR_H

#include "allocator.h"

template<class T, class A = allocator<T>>
class vector
{
private:
	A alloc;
	T * elements;
	int size;
	int capacity;
public:
	vector()
		: vector(0) {};
	explicit vector(int size)
		: elements(alloc.allocate(size)), size(size), capacity(size) {};
	
	~vector() { alloc.deallocate(elements, capacity); }
	vector(const vector& other); // copy constructor
	vector& operator=(const vector& other); // copy assignment

	const T& operator[](int index) const { return elements[index]; }
	T& operator[](int index) { return elements[index]; }
	
	int getSize() const { return this->size; }
	int getCapacity() const { return this->capacity; }
	
	void push_back(T val);
	void resize(int newsize, T def = T());
	void reserve(int newalloc);
};

#include "vector.tpp"
#endif // VECTOR_H

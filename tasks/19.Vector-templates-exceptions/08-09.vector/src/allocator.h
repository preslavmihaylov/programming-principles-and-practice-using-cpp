#ifndef ALLOCATOR_H
#define ALLOCATOR_H

template<class T>
class allocator
{
public:
	T* allocate(int n);
	void deallocate(T* p, int n);

	void construct(T* p, const T& v);
	void destroy(T* p);
};

#include "allocator.tpp"
#endif // ALLOCATOR_H

#include "allocator.h"
#include <cstdlib>

template<class T>
T* allocator<T>::allocate(int n)
{
	T* res = (T*)malloc(sizeof(T) * n);
	return res;
}

template<class T>
void allocator<T>::deallocate(T* p, int n)
{
	free(p);
}

template<class T>
void allocator<T>::construct(T* p, const T& v)
{
	*p = v;
}

template<class T>
void allocator<T>::destroy(T* p)
{
	p->~T();
}

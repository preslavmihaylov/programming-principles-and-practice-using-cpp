#ifndef COUNTED_PTR_H
#define COUNTED_PTR_H

template<class T>
class counted_ptr
{
private:
	T * ptr;
	int * cnt;
	void destroyPtr();
public:
	counted_ptr(T * pointer)
		: ptr(pointer) { cnt = new int(1); }
	
	~counted_ptr(); // destructor
	counted_ptr(const counted_ptr& other); // copy constructor
	counted_ptr& operator=(const counted_ptr& other); // copy assignment

	T& operator*() { return *ptr; }
	T* operator->() { return ptr; }

	T* get() const { return ptr; }
	int count() const { return *cnt; }
};

#include "counted_ptr.tpp"
#endif // COUNTED_PTR_H

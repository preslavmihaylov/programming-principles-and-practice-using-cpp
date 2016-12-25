#include <iostream>

using namespace std;

template<class T>
struct auto_ptr
{
	T * ptr;
	auto_ptr(T* pointer)
		: ptr(pointer) {};
	~auto_ptr() { delete ptr; }
	
	T& operator*() const { return *ptr; }
	T* operator->() const { return ptr; }

	T* get() const { return ptr; }
	T* release() 
	{ 
		T * returnedVal = ptr;
		ptr = NULL;
		return returnedVal;
	}
};

int main()
{
	auto_ptr<int> p(new int[10]);

	for (int i = 0; i < 10; ++i) 
	{
		p.get()[i] = i;
		cout << p.get()[i] << endl;
	}
	
	return 0;
}

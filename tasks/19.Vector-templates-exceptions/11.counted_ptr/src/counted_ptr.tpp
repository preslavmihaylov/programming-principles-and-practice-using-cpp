#include <iostream>

using namespace std;

template<class T>
counted_ptr<T>::~counted_ptr() // destructor
{
	destroyPtr();
}

template<class T>
counted_ptr<T>::counted_ptr(const counted_ptr& other) // copy constructor
{
	ptr = other.ptr;
	cnt = other.cnt;
	++(*cnt);
	cout << "Ptr created. Cnt left: " << *cnt << endl;
}

template<class T>
counted_ptr<T>& counted_ptr<T>::operator=(const counted_ptr& other) // copy assignment
{
	destroyPtr();

	ptr = other.ptr;
	cnt = other.cnt;
	++(*cnt);
}

template<class T>
void counted_ptr<T>::destroyPtr()
{
	--(*cnt);
	cout << "Ptr destroyed. Cnt left: " << *cnt << endl;
	if (*cnt <= 0) 
	{
		delete ptr;
		delete cnt;
	}
}

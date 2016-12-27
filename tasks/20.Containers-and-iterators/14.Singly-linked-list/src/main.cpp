#include <iostream>

#include "list.h"

using namespace std;

int main()
{
	list<int> l;
	list<int>::iterator it = l.begin();
	l.push_front(10);
	l.push_front(20);
	l.push_front(30);
	l.push_front(40);
	
	l.erase(l.begin());

	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << endl;	
	}
	
	cout << "First element: " << l.front() << endl;

	cout << "deleted 2 elements" << endl;
	l.pop_front();
	l.pop_front();
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << endl;	
	}
	
	cout << "First element: " << l.front() << endl;
	
	return 0;
}

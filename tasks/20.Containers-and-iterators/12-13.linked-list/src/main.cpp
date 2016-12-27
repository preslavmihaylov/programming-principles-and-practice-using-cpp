#include <iostream>

#include "list.h"

using namespace std;

int main()
{
	list<int> l;
	list<int>::iterator it = l.begin();
	it = l.insert(it, 10);
	it = l.insert(it, 20);
	it = l.insert(it, 30);
	it = l.insert(it, 40);
	
	it = l.erase(it);

	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << endl;	
	}
	
	cout << "First element: " << l.front() << endl;
	cout << "Last element: " << l.back() << endl;

	cout << "deleted 2 elements" << endl;
	it = l.erase(it);
	it = l.erase(it);
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << endl;	
	}
	
	cout << "First element: " << l.front() << endl;
	cout << "Last element: " << l.back() << endl;
	
	cout << "Pop back" << endl;
	l.pop_back();

	cout << "elements left: " << endl;
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << endl;	
	}

	cout << "pushed back 5 elements" << endl;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	l.push_back(4);
	l.push_back(5);
	
	cout << "elements left: " << endl;
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << endl;	
	}

	cout << "pop front 2 elements" << endl;
	l.pop_front();
	l.pop_front();
	
	cout << "elements left: " << endl;
	for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
	{
		cout << *it << endl;	
	}
	
	return 0;
}

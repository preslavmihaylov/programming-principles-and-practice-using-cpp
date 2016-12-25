#include <iostream>
#include "vector.h"
//#include <vector>

using namespace std;

struct A
{
	int val;
	A(int value) : val(value) {};
};

int main()
{
	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	vector<int> b = a; // copy constructor
	vector<int> c;
	c = a; // copy assignment

	cout << "a elements" << endl;
	for (int i = 0; i < a.getSize(); ++i) cout << a[i] << endl;
	cout << "b elements" << endl;
	for (int i = 0; i < a.getSize(); ++i) cout << b[i] << endl;
	cout << "c elements" << endl;
	for (int i = 0; i < a.getSize(); ++i) cout << c[i] << endl;
	
	cout << "Size: " << a.getSize() << endl;
	cout << "Capacity: " << a.getCapacity() << endl;
	
	vector<A> no_default;
	no_default.push_back(5);
	no_default.resize(8, 20);
	// no_default.resize(8); - this doesnt work
	cout << no_default[0].val << endl;

	return 0;
}

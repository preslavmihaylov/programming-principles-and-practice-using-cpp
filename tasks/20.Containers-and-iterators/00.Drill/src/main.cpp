#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<class Iter1, class Iter2>
void m_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	if (f1 == e1) return;
	while (f1 != e1)
	{
		*f2 = *f1;
		++f1;
		++f2;
	}
}

int main()
{
	int a[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<int> v = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> l = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int * ac = a;
	vector<int> vc = v;
	list<int> lc = l;

	// increase val by 2
	for (int * i = a; i != a+10; ++i) *i += 2;
	for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) *i += 3;
	for (list<int>::iterator i = l.begin(); i != l.end(); ++i) *i += 5;
	
	m_copy((a+0), (a+10), v.begin());
	m_copy(l.begin(), l.end(), (a+0));
	for (int i = 0; i < 10; ++i) cout << a[i] << endl;
	cout << endl;
	for (int i = 0; i < 10; ++i) cout << v[i] << endl;
	
	// find element 3 in vector
	vector<int>::iterator foundVal = find(v.begin(), v.end(), 3);
	if (foundVal == v.end()) cout << "3 not found" << endl;
	else
	{
		int pos = foundVal - v.begin();
		cout << "3 found at position " << pos << endl;
	}

	return 0;
}

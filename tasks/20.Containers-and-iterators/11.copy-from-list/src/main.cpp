#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
	list<double> lst;
	vector<double> v;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	lst.push_back(5);

	v.clear();
	for (list<double>::iterator p = lst.begin(); p != lst.end(); ++p)
	{
		v.push_back(*p);
	}

	for (int i = 0; i < v.size(); ++i) cout << v[i] << endl;

	return 0;
}

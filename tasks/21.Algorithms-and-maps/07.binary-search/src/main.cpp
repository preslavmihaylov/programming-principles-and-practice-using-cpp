#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

template<class Iterator, class T>
bool binarySearch(Iterator first, Iterator last, const T& val)
{
	first = lower_bound(first, last, val);
	return (first != last) && (val == (*first));
}

int main()
{
	vector<int> vi = { 43, 35, 11, 98, 34, 343, 565, 223, 656 };
	list<int> li = { 43, 35, 11, 98, 34, 343, 565, 223, 656 };
	sort(vi.begin(), vi.end());
	li.sort();

	bool isPresent = binarySearch(vi.begin(), vi.end(), 43);
	cout << "Is 43 present in vector? " << isPresent << endl;
	isPresent = binarySearch(li.begin(), li.end(), 43);
	cout << "Is 43 present in list? " << isPresent << endl;

	return 0;
}

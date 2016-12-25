#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

template<class T>void add(vector<T>& f, vector<T>& s)
{
	for (int i = 0; i < s.size(); ++i) f.push_back(s[i]);
}

int main()
{
	vector<int> a = { 1, 2, 3, 4 };
	vector<int> b = { 5, 6, 7, 8 };
	add(a, b);
	for (int i = 0; i < a.size(); ++i) cout << a[i] << endl;
	
	return 0;
}

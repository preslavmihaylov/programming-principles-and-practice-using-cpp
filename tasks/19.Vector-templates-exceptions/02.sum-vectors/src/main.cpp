#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

template<class T, class U>double sum(vector<T>& f, vector<U>& s)
{
	double res = 0;
	if (f.size() != s.size()) throw runtime_error("Different sizes");

	for (int i = 0; i < f.size(); ++i) res += f[i] * s[i];

	return res;
}

int main()
{
	vector<int> a = { 1, 2, 3, 4 };
	vector<double> b = { 5, 6, 7, 8 };
	double res = sum(a, b);
	cout << res;

	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

vector<int> gv = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };

void f(vector<int> v)
{
	vector<int> lv(v.size());
	lv = gv;
	for (int i = 0; i < lv.size(); ++i) cout << lv[i] << " ";
	cout << '\n';
	vector<int> lv2 = v;
	for (int i = 0; i < lv2.size(); ++i) cout << lv2[i] << " ";
	cout << '\n';
}

int fact(int n)
{ return (n > 1 ? n * fact(n - 1) : 1); }

int main()
{
	f(gv);
	vector<int> vv(10);
	for (int i = 0; i < 10; ++i) vv[i] = fact(i + 1);
	f(vv);
	return 0;
}

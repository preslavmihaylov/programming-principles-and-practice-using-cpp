#include <iostream>
#include <vector>

using namespace std;

string getLastString(vector<string>& v)
{
	string result = "";
	for (vector<string>::iterator p = v.begin(); p != v.end(); ++p)
	{
		if (result < *p) result = *p;
	}

	return result;
}

int main()
{
	vector<string> strings = { "pesho", "minka", "zzzz", "aaaa" };
	string res = getLastString(strings);
	cout << res << endl;
	return 0;
}

#include <iostream>

using namespace std;

string cat_dot(const string& s1, const string& s2, const string& del)
{
	return s1 + del + s2;
}

int main()
{
	string res = cat_dot("Niels", "Bohr", ".");
	cout << res << endl;

	res = cat_dot("Niels", "Bohr", "---");
	cout << res << endl;
	
	return 0;
}

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <climits>

using namespace std;

template<class T> struct S
{
	S(T value) : val(value) {};
	S() : val(T()) {};

	const T& operator[](int index) const;
	T& operator[](int index);
private:
	T val;
};

template<class T>void read_val(T& v)
{
	cin >> v;
}

template<class T>istream& operator>>(istream& is, vector<T>& v)
{
	string input;
	
	is.ignore(INT_MAX, '\n');
	getline(cin, input);
	stringstream ss(input);

	T val;
	while (ss >> val) v.push_back(val);
	
	return is;
}

template<class T>T& S<T>::operator[](int index) { return val; }
template<class T>const T& S<T>::operator[](int index) const { return val; }

int main()
{
	S<int> si;
	S<char> sc;
	S<double> sd;
	S<string> ss;
	S<vector<int>> sv;
	
	read_val(si[0]);
	read_val(sc[0]);
	read_val(sd[0]);
	read_val(ss[0]);
	read_val(sv[0]);

	cout << si[0] << endl;
	cout << sc[0] << endl;
	cout << sd[0] << endl;
	cout << ss[0] << endl;
	cout << sv[0][0] << endl;
	return 0;
}

#include <iostream>

using namespace std;

class Int
{
	int value;

public:
	Int()
		: value(0) {};
	Int(int value) 
		: value(value) {};
	
	Int operator+(Int& other) { return this->value + other.value; }
	Int operator-(Int& other) { return this->value - other.value; }	
	Int operator*(Int& other) { return this->value * other.value; }	
	Int operator/(Int& other) { return this->value / other.value; }	

	friend ostream& operator<<(ostream& os, const Int& num)
	{
		os << num.value;
		return os;
	}

	friend istream& operator>>(istream& is, Int& num)
	{
		is >> num.value;
		return is;
	}
};

int main()
{
	Int a = 5;
	Int b = 10;
	Int c;
	cout << (a + b) << endl;
	cout << (a - b) << endl;
	cout << (a * b) << endl;
	cout << (a / b) << endl;
	cout << (a + b + c + a) << endl;
	
	cin >> c;
	cout << (a + c) << endl;
	return 0;
}

#include <iostream>
#include <vector>

using namespace std;

template<
	typename T,	
	typename = typename enable_if<is_arithmetic<T>::value, T>::type
>
class Number
{
	T value;

public:
	Number()
		: value(T()) {};
	Number(T value) 
		: value(value) {};
	
	Number operator+(Number& other) { return this->value + other.value; }
	Number operator-(Number& other) { return this->value - other.value; }	
	Number operator*(Number& other) { return this->value * other.value; }	
	Number operator/(Number& other) { return this->value / other.value; }	
	Number operator%(Number& other) { return this->value % other.value; }	

	friend ostream& operator<<(ostream& os, const Number& num)
	{
		os << num.value;
		return os;
	}

	friend istream& operator>>(istream& is, Number& num)
	{
		is >> num.value;
		return is;
	}
};

class A {};

int main()
{
	Number<int> a = 5;
	Number<int> b = 10;
	Number<int> c;
	
	cout << (a + b) << endl;
	cout << (a - b) << endl;
	cout << (a * b) << endl;
	cout << (a / b) << endl;
	cout << (a + b + c + a) << endl;
	
	cin >> c;
	cout << (a + c) << endl;
	
	Number<double> d = 5.5;
	Number<double> e = 10;
	// this fails
	// cout << (d % e) << endl;

	return 0;
}

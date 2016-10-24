#include <iostream>
#include <iomanip>

using namespace std;

void printInfoField()
{
	cout 
		<< '|' << setw(16) << left << "Preslav" 
		<< '|' << setw(16) << "Mihaylov" 
		<< '|' << setw(16) << "0888888888"
		<< '|' << setw(16) << "press@gmail.com"
		<< '|' << endl;
}

int main()
{
	int birthYear = 1995;
	int age = 21;
	int a, b, c, d;
	double doubleNum;

	cout << showbase;
	cout << "Year in hex\t" << hex << birthYear << endl;
	cout << "Year in dec\t" << dec << birthYear << endl;
	cout << "Year in oct\t" << oct << birthYear << endl;
	
	cout << "Age\t" << dec << age << endl;

	cin >> a >> oct >> b >> hex >> c >> d;
	cout << a << '\t' << b << '\t' << c << '\t' << d << endl;

	cin >> doubleNum;
	cout << "general double form:\t" << doubleNum << endl;
	cout << "fixed double form:\t" << fixed << doubleNum << endl;
	cout << "scientific double form:\t" << scientific << doubleNum << endl;

	printInfoField();
	return 0;
}

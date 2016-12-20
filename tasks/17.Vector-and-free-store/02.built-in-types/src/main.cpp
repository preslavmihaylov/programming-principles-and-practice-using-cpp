#include <iostream>

using namespace std;

int main()
{
	cout << "short is: " << (sizeof(short)*8) << " bits big" << endl;
	cout << "int is: " << (sizeof(int)*8) << " bits big" << endl;
	cout << "long is: " << (sizeof(long)*8) << " bits big" << endl;
	cout << "long long is: " << (sizeof(long long)*8) << " bits big" << endl;
	cout << "bool is: " << (sizeof(bool)*8) << " bits big" << endl;
	cout << "float is: " << (sizeof(float)*8) << " bits big" << endl;
	cout << "double is: " << (sizeof(double)*8) << " bits big" << endl;
	return 0;
}

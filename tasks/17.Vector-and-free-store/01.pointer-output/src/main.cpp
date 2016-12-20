#include <iostream>

using namespace std;

int main()
{
	int* p1 = new int[10];
	cout << p1 << endl;
	delete[] p1;

	return 0;
}

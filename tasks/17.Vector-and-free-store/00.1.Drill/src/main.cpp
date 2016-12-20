#include <iostream>

using namespace std;

void print_arr10(ostream& os, int* a)
{
	for (int i = 0; i < 10; ++i)
	{
		os << a[i] << endl;
	}
}

void print_arr(ostream& os, int* a, int n)
{
	for (int i = 0; i < n; ++i)
	{
		os << a[i] << endl;
	}
}

int main()
{
	int* int_arr = new int[10];
	int i;

	for (i = 0; i < 10; ++i)
	{
		cout << int_arr[i] << endl;
	}
	
	delete[] int_arr;

	int_arr = new int[10];

	for (i = 0; i < 10; ++i)
	{
		int_arr[i] = i + 100;
	}
	
	print_arr10(cout, int_arr);
	delete[] int_arr;
	int_arr = new int[11];
	for (i = 0; i < 11; ++i)
	{
		int_arr[i] = i + 100;
	}
	
	print_arr10(cout, int_arr);
	delete[] int_arr;
	int_arr = new int[20];
	for (i = 0; i < 20; ++i)
	{
		int_arr[i] = i + 100;
	}

	print_arr(cout, int_arr, 20);
	delete[] int_arr;

	return 0;
}

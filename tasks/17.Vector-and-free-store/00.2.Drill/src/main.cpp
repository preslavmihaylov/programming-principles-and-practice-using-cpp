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
		os << a[i] << ' ';
	}

	os << '\n';
}

int main()
{
	int val = 7;
	int* p1 = &val;

	cout << p1 << " " << val << endl;

	int arr[7] = { 1, 2, 4, 8, 16, 32, 64 };
	int* p2 = arr;

	cout << p2 << " ";
	print_arr(cout, arr, 7);
	int* p3 = p2;
	p2 = p1;
	p2 = p3;

	cout << p2 << ' ';
	print_arr(cout, p2, 7);

	// 10-12
	p1 = new int[10];
	int i;
	int power2 = 1;
	for (i = 0; i < 10; ++i)
	{
		p1[i] = power2;
		power2 *= 2;
	}
	
	p2 = new int[10];
	for (i = 0; i < 10; ++i)
	{
		p2[i] = p1[i];
	}

	print_arr(cout, p2, 10);
	return 0;
}

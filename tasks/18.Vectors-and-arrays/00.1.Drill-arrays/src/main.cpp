#include <iostream>
#include <vector>

using namespace std;

int ga[10] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 }; 

void f(int * arr, int n)
{
	int la[10];
	int* p = new int[n];
	int i;

	for (i = 0; i < n; ++i) 
	{
		la[i] = ga[i];
		cout << la[i] << " ";
	}
	cout << '\n';

	for (i = 0; i < n; ++i)
	{
		p[i] = arr[i];
		cout << p[i] << " ";
	}
	cout << '\n';

	delete[] p;
}

long long fact(int n)
{
	return (n > 1 ? n * fact(n - 1) : 1);
}

int main()
{
	f(ga, 10);
	int aa[10];
	for (int i = 0; i < 10; ++i) aa[i] = fact(i + 1);
	f(aa, 10);

	return 0;
}

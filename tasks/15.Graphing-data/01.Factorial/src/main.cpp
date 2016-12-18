#include <iostream>
#include <string>

using namespace std;

int fact(int n)
{
	return (n <= 1 ? 1 : n * fact(n - 1));
}

int main()
{
	cout << fact(5) << endl;
	return 0;
}

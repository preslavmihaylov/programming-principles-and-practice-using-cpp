#include <iostream>

using namespace std;

int main()
{
	int first = 10;
	int second = 20;

	// first is with higher address --> stack grows downwards
	cout << "Statically allocated var (1) memory:" << &first << endl;
	cout << "Statically allocated var (2) memory:" << &second << endl;
	
	int* firstAlloc = new int[10];
	int* secondAlloc = new int[10];

	// first is with lower address --> heap grows upwards
	cout << "Heap allocated var (1) memory: " << firstAlloc << endl;
	cout << "Heap allocated var (2) memory: " << secondAlloc << endl;
	
	return 0;
}

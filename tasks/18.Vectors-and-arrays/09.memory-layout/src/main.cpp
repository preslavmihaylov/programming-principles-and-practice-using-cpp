#include <iostream>

using namespace std;

int g1 = 10;
int g2 = 20;

int main()
{
	int l1 = 10;
	int l2 = 20;

	int * p1 = new int(10);
	int * p2 = new int(20);

	cout << "Static var (1) address is " << &g1 << endl;
	cout << "Static var (2) address is " << &g2 << endl;
	cout << "difference in their addresses is " << (&g1 - &g2) << endl;
	cout << "which means static storage grows " << 
		((&g1 - &g2) < 0 ? "upwards" : "downwards") << endl;

	cout << endl;
	cout << "Stack var (1) address is " << &l1 << endl;
	cout << "Stack var (2) address is " << &l2 << endl;
	cout << "difference in their addresses is " << (&l1 - &l2) << endl;
	cout << "which means stack storage grows " << 
		((&l1 - &l2) < 0 ? "upwards" : "downwards") << endl;
	
	cout << endl;
	cout << "Heap var (1) address is " << p1 << endl;
	cout << "Heap var (2) address is " << p2 << endl;
	cout << "difference in their addresses is " << (p1 - p2) << endl;
	cout << "which means heap storage grows " << 
		((p1 - p2) < 0 ? "upwards" : "downwards") << endl;
	
	delete p1;
	delete p2;

	return 0;
}

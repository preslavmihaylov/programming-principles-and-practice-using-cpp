#include <iostream>
#include <bitset>

using namespace std;

int main()
{
	// from 0 to 400
	for (int i = 0; i <= 400; ++i) 
		cout << dec << i << " -> " << hex << i << endl;
	// from -200 to 200
	for (int i = -200; i <= 200; ++i) 
		cout << dec << i << " -> " << hex << i << endl;
	return 0;
}

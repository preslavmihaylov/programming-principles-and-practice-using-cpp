#include <iostream>
#include "counted_ptr.h"

using namespace std;

void fillPtr(counted_ptr<int> p)
{
	for (int i = 0; i < 10; ++i) p.get()[i] = i;	
}

int main()
{
	counted_ptr<int> p(new int[10]);
	fillPtr(p);
	for (int i = 0; i < 10; ++i) cout << p.get()[i] << endl;

	return 0;
}

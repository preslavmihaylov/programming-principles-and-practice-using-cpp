#include <iostream>
#include <bitset>
#include <climits>

using namespace std;

int main()
{
	unsigned int num = -1;
	int cnt = 0;
	while (num)
	{
		num >>= 1;
		++cnt;
	}

	cout << "Num bits in int: " << cnt << endl;
	
	char c = 0xFF / 2 + 1;
	if (c < (char)0) cout << "char is signed" << endl;
	else cout << "char is unsigned" << endl;
	
	return 0;
}

#include <iostream>
#include <bitset>

using namespace std;

template<class T>
void printNum(T num)
{
	bitset<sizeof(num) * 8> bin(num);
	cout << "DEC " << std::dec << num 
		 << " HEX: " << std::hex << num
		 << " BIN: " << bin
		 << endl;
}

int main()
{
	int num;
	// all zeroes
	num = 0;
	printNum(num);
	
	// all ones
	num = -1;
	printNum(num);
	
	// alternating ones and zeroes (starting with 1)
	num = 0;
	num |= 0x55555555;
	printNum(num);
	
	// alternating ones and zeroes (starting with 0)
	num = 0;
	num |= 0xAAAAAAAA;
	printNum(num);
	
	return 0;
}

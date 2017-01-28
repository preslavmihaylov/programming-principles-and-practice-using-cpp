#include <iostream>
#include <bitset>

using namespace std;

void printNum(short unsigned int num)
{
	bitset<sizeof(num) * 8> bin(num);
	cout << "DEC " << std::dec << num 
		 << " HEX: " << std::hex << num
		 << " BIN: " << bin
		 << endl;
}

int main()
{
	// 1. & 2.
	unsigned int v = 1;
	for (int i = 0; i < sizeof(v) * 8; ++i)
	{
		cout << v << ' ';
		v <<= 1;
	}
	
	cout << endl;

	// 3.a all ones
	short unsigned int num;
	num |= 0xFFFF;
	printNum(num);

	// 3.b LSB set
	num &= 0x01;
	printNum(num);

	// 3.c MSB set
	num = 0;
	num |= (short unsigned int)0x01 << (sizeof(num) * 8) - 1;
	printNum(num);
	
	// 3.d Lowest byte set
	num = 0;
	num |= 0x00FF;
	printNum(num);
	
	// 3.e Highest byte set
	num = 0;
	num |= 0xFF00;
	printNum(num);

	// 3.f Every second bit set, lowest is 1
	num = 1;
	num |= 0xAAAA;
	printNum(num);
	
	// 3.f Every second bit set, lowest is 0
	num = 0;
	num |= 0xAAAA;
	printNum(num);
	
	return 0;
}

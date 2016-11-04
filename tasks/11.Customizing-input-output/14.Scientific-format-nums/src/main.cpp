#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	fstream inputStream("input.txt");
	double currentNum;
	
	if (!inputStream)
	{
		cout << "Cannot open input file\n";
		return 1;
	}

	cout << scientific << setprecision(8);
	while (inputStream >> currentNum)
	{
		cout << setw(20) << currentNum << '\n';
	}

	return 0;
}

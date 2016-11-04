#include <iostream>
#include <fstream>
#include <map>

using namespace std;

map<int, int> numCounts;

int main()
{
	fstream inputStream("numbers.txt");
	int currentNum;

	if (!inputStream)
	{
		cout << "Failed to open input file\n";
	}

	while (inputStream >> currentNum)
	{
		// If key does not exist, create it
		if (numCounts.find(currentNum) == numCounts.end())
		{
			numCounts[currentNum] = 0;
		}

		numCounts[currentNum]++;
	}
	
	for (const auto& numKeyValue : numCounts)
	{
		cout << numKeyValue.first << "\t";
		if (numKeyValue.second > 1)
		{
			cout << numKeyValue.second;
		}

		cout << '\n';
	}

	return 0;
}

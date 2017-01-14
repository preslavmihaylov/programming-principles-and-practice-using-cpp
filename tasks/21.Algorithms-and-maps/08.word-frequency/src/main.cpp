#include <iostream>
#include <map>
#include <fstream>

using namespace std;

int main()
{
	map<string, int> wordFreq;
	map<int, string> wordFreqByCnt;
	ifstream inputStream("input.txt");

	string word;
	while (inputStream >> word) ++wordFreq[word];

	for (pair<string, int> kv : wordFreq)
	{
		wordFreqByCnt[kv.second] = kv.first;
	}

	for (pair<int, string> kv : wordFreqByCnt)
	{
		cout << kv.first << " : " << kv.second << endl;
	}

	return 0;
}

#include <iostream>
#include <vector>
#include <ctime>
#include <set>
#include <algorithm>

using namespace std;

#define FIRST_THRESHOLD 500000
#define SECOND_THRESHOLD 5000000

void testMap()
{
	set<double> m;
	clock_t startClk;
	clock_t endClk;
	double elapsedSeconds;

	startClk = clock();
	for (int i = 0; i < FIRST_THRESHOLD; ++i)
	{
		double d = rand();
		m.insert(d);
	}

	endClk = clock();
	elapsedSeconds = 
		double(endClk - startClk) / CLOCKS_PER_SEC;

	cout << "Test " << FIRST_THRESHOLD << " doubles sorted with map: "
		 << elapsedSeconds << " secs\n";

	m.clear();
	startClk = clock();
	for (int i = 0; i < SECOND_THRESHOLD; ++i)
	{
		double d = rand();
		m.insert(d);
	}

	endClk = clock();
	elapsedSeconds = 
		double(endClk - startClk) / CLOCKS_PER_SEC;

	cout << "Test " << SECOND_THRESHOLD << " doubles sorted with map: "
		 << elapsedSeconds << " secs\n";
}


void testVector()
{
	vector<double> v;
	clock_t startClk;
	clock_t endClk;
	double elapsedSeconds;

	startClk = clock();
	for (int i = 0; i < FIRST_THRESHOLD; ++i)
	{
		double d = rand();
		v.push_back(d);
	}

	sort(v.begin(), v.end());
	endClk = clock();
	elapsedSeconds = 
		double(endClk - startClk) / CLOCKS_PER_SEC;

	cout << "Test " << FIRST_THRESHOLD << " doubles sorted with vector: "
		 << elapsedSeconds << " secs\n";

	v.clear();
	startClk = clock();
	for (int i = 0; i < SECOND_THRESHOLD; ++i)
	{
		double d = rand();
		v.push_back(d);
	}

	sort(v.begin(), v.end());
	endClk = clock();
	elapsedSeconds = 
		double(endClk - startClk) / CLOCKS_PER_SEC;

	cout << "Test " << SECOND_THRESHOLD << " doubles sorted with vector: "
		 << elapsedSeconds << " secs\n";
}

int main()
{
	srand(time(NULL));
	testVector();
	testMap();
	return 0;
}

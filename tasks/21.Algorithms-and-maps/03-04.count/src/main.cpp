#include <iostream>
#include <vector>

using namespace std;

template<class Iterator>
int count(Iterator start, Iterator end)
{
	int cnt = 0;
	while (start != end)
	{
		++cnt;
		++start;
	}

	return cnt;
}

template<class Iterator, class Condition>
int count_if(Iterator start, Iterator end, Condition cond)
{
	int cnt = 0;
	while (start != end)
	{
		if (cond(*start)) ++cnt;
		++start;
	}

	return cnt;
}

struct isOdd
{
	bool operator()(int val) { return (val % 2); }
};

int main()
{
	vector<int> vi = { 1, 2, 3, 4, 5 };
	int cnt = count(vi.begin(), vi.end());

	cout << "Cnt: " << cnt << endl;
	cnt = count_if(vi.begin(), vi.end(), isOdd());
	cout << "Odd cnt: " << cnt << endl;
	
	return 0;
}

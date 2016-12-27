#include <iostream>
#include <vector>
#include <list>
#include <cstdlib>
#include <ctime>

using namespace std;

void measureVector(int N)
{
	vector<int> v = { 0 };
	int currentNumber;
	
	clock_t begin = clock();
	// vector metrics
	for (int i = 0; i < N; ++i)
	{
		currentNumber = rand();
		bool inserted = false;
		for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		{
			if (*it > currentNumber) 
			{
				v.insert(it, currentNumber);
				inserted = true;
				break;
			}
		}

		if (!inserted) v.push_back(currentNumber);
	}

	clock_t end = clock();
	double elapsed = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Vector elapsed time: " << elapsed << endl;
}

void measureList(int N)
{
	list<int> l;
	l.push_back(0);
	int currentNumber;
	
	clock_t begin = clock();
	// list metrics
	for (int i = 0; i < N; ++i)
	{
		currentNumber = rand();
		bool inserted = false;
		for (list<int>::iterator it = l.begin(); it != l.end(); ++it)
		{
			if (*it > currentNumber) 
			{
				l.insert(it, currentNumber);
				inserted = true;
				break;
			}
		}

		if (!inserted) l.push_back(currentNumber);
	}

	clock_t end = clock();
	double elapsed = double(end - begin) / CLOCKS_PER_SEC;
	cout << "List elapsed time: " << elapsed << endl;
}

int main()
{
	srand(time(NULL));

	int N = 100;
	cout << "N = 100" << endl;
	measureVector(N);
	measureList(N);

	N = 1000;
	cout << "N = 1000" << endl;
	measureVector(N);
	measureList(N);
	
	N = 10000;
	cout << "N = 10000" << endl;
	measureVector(N);
	measureList(N);
	
	N = 20000;
	cout << "N = 20000" << endl;
	measureVector(N);
	measureList(N);
	
	N = 40000;
	cout << "N = 40000" << endl;
	measureVector(N);
	measureList(N);
	
	return 0;
}

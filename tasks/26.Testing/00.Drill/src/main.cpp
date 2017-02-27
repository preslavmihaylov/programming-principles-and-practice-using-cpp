#include <iostream>
#include <vector>

using namespace std;

template<class T>
struct Test 
{
	string label;
	T val;
	vector<T> seq;
	bool res;
};

template<class T>
istream& operator>>(istream& is, vector<T>& vec)
{
	char seqStart, delim;
	T num;
	is >> seqStart;

	vec.clear();
	if (is)
	{
		if (seqStart == '{')
		{
			is >> delim;
			while (delim != '}')
			{
				is.putback(delim);
				is >> num;
				if (is)
				{
					vec.push_back(num);
				}
				else
				{
					break;
				}

				is >> delim;
			}
		}
		else
		{
			is.clear(ios_base::failbit);
		}
	}

	return is;
}

template<class T>
istream& operator>>(istream& is, Test<T>& t)
{
	char testStart, testEnd;

	is >> testStart 
	   >> t.label 
	   >> t.val 
	   >> t.seq 
	   >> t.res 
	   >> testEnd;
	
	if (is)
	{
		if (testStart != '{' || testEnd != '}')
		{
			is.clear(ios_base::failbit);
		}
	}
	
	return is;
}

template<class T>
bool binSearch(vector<T> & nums, T searched)
{
	int start = 0;
	int end = nums.size();
	int middle;

	while (start < end)
	{
		middle = start + (end - start) / 2;
		if (nums[middle] == searched)
		{
			return true;
		}
		else if (nums[middle] > searched)
		{
			end = middle;
		}
		else // if (nums[middle] < searched)
		{
			start = middle + 1;
		}
	}

	return false;
}

int test_all()
{
	int errCnt = 0;
	Test<int> t;
	while (cin >> t)
	{
		bool r = binSearch(t.seq, t.val);
		if (r != t.res)
		{
			cout << "failure: test " << t.label
			     << " binary search: "
				 << t.seq.size() << " elements, val=="
				 << t.val << " -> " << t.res << '\n';
			++errCnt;
		}
		else
		{
			cout << "Test " << t.label << " Passed successfully\n";
		}
	}

	return errCnt;
}

int main()
{
	int errCnt = test_all();
	cout << "Number of errors: " << errCnt << '\n';
	return 0;
}

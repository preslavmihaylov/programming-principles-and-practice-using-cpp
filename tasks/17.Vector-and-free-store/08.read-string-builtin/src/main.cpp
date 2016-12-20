#include <iostream>

using namespace std;

int main()
{
	string str;
	char currentCh;
	cin >> currentCh;

	while (currentCh != '!')
	{
		str += currentCh;
		cin >> currentCh;
	}
	
	cout << str << endl;
	return 0;
}

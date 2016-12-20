#include <iostream>

using namespace std;

int main()
{
	int capacity = 8;
	char* str = (char*)malloc(sizeof(char) * capacity);
	int cnt = 0;
	char currentCh;
	cin >> currentCh;

	while (currentCh != '!')
	{
		str[cnt++] = currentCh;
		cin >> currentCh;
		if (cnt > capacity)
		{
			capacity *= 2;
			str = (char*)realloc(str, sizeof(char) * capacity);
		}
	}
	
	str[cnt] = '\0';

	cout << str << endl;
	delete[] str;
	
	return 0;
}

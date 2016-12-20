#include <iostream>

using namespace std;

char * strdup(const char * str)
{
	int cnt = 0;
	while (str[cnt] != '\0') cnt++;

	char* newStr = new char[cnt];
	for (int i = 0; i < cnt; ++i)
	{
		newStr[i] = str[i];
	}
	
	return newStr;
}

int main()
{
	char str[] = "abcd";
	char * allocStr = strdup(str);
	cout << allocStr << endl;
	delete[] allocStr;

	return 0;
}

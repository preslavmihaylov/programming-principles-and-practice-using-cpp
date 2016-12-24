#include <iostream>
#include <vector>

using namespace std;

char* strdup(const char* str)
{
	int strSize = 0;
	while (*(str+strSize) != '\0') ++strSize;

	int i = 0;
	char* newStr = new char[strSize];
	while (*(str+i) != '\0') 
	{
		*(newStr+i) = *(str+i);
		++i;
	}

	*(newStr+i) = '\0';
	return newStr;
}

int main()
{
	char * str = strdup("Hello");
	cout << str << endl;
	delete[] str;
	return 0;
}

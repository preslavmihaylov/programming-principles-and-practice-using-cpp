#include <iostream>

using namespace std;

void toLower(char * str)
{
	for (int i = 0; str[i] != '\0'; ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = (str[i] - 'A') + 'a';
		}
	}
}

int main()
{
	char str[] = "HeLlO TheRe!";
	
	toLower(str);
	cout << str << endl;
	return 0;
}

#include <iostream>

using namespace std;

bool isPalindrome(const char* str)
{
	int strLength = 0;
	while (*(str+strLength) != '\0') ++strLength;

	char* buffer = new char[strLength];
	int i = 0;
	int j = strLength - 1;

	while (i < strLength) buffer[i++] = str[j--];

	bool areEqual = true;
	i = 0;
	while (areEqual && i < strLength)
	{
		if (buffer[i] != str[i])
		{
			areEqual = false;
		}

		++i;
	}

	return areEqual;
}

int main()
{
	{
		char sentence[] = "heleh";

		cout << sentence 
			 << " is palindrome? " 
			 << isPalindrome(sentence) 
			 << endl; 
	}

	{
		char sentence[] = "bella";

		cout << sentence 
			 << " is palindrome? " 
			 << isPalindrome(sentence) 
			 << endl; 
	}
	
	return 0;
}

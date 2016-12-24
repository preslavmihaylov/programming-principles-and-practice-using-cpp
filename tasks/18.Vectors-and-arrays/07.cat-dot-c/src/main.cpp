#include <iostream>

using namespace std;

char* cat_dot(const char* s1, const char* s2, const char* del)
{
	int s1Size = 0;
	int s2Size = 0;
	int delSize = 0;
	while (*(s1+s1Size) != '\0') ++s1Size;
	while (*(s2+s2Size) != '\0') ++s2Size;
	while (*(del+delSize) != '\0') ++delSize;
	
	char* newStr = new char[s1Size + s2Size + delSize + 1];
	char * newStrP = newStr;

	while (*s1 != '\0') 
	{
		*newStrP = *s1;
		++newStrP;
		++s1;
	}
	
	while (*del != '\0') 
	{
		*newStrP = *del;
		++newStrP;
		++del;
	}
	
	while (*s2 != '\0') 
	{
		*newStrP = *s2;
		++newStrP;
		++s2;
	}
	
	*newStrP = '\0';
	return newStr;
}

int main()
{
	char * res = cat_dot("Niels", "Bohr", ".");
	cout << res << endl;
	delete[] res;

	res = cat_dot("Niels", "Bohr", "---");
	cout << res << endl;
	delete[] res;

	return 0;
}

#include <iostream>

using namespace std;

int strcmp(const char* s1, const char* s2)
{
	int i = 0;

	while ((*(s1+i) == *(s2+i)) && 
		   (*(s1+i) != '\0') && 
		   (*(s2+i) != '\0')) 
		++i;

	if (*(s1+i) < *(s2+i)) return -1;
	else if (*(s1+i) > *(s2+i)) return 1;
	else return 0;
}

int main()
{
	{
		char s1[] = "ABCDEF";
		char s2[] = "ABCDDF";
		cout << s1 << " ? " << s2 << " " << strcmp(s1, s2) << endl;
	}

	{
		char s1[] = "ABCDEF";
		char s2[] = "ABCDEF";
		cout << s1 << " ? " << s2 << " " << strcmp(s1, s2) << endl;
	}
	
	{
		char s1[] = "AACDEF";
		char s2[] = "ABCDEF";
		cout << s1 << " ? " << s2 << " " << strcmp(s1, s2) << endl;
	}
	
	{
		char s1[] = "ABCD";
		char s2[] = "ABCDEF";
		cout << s1 << " ? " << s2 << " " << strcmp(s1, s2) << endl;
	}
	
	return 0;
}

#include <iostream>

using namespace std;

bool strContains(const char* s, const char* x)
{
	bool doesContain = true;
	const char* pS = s;
	const char* pX = x;
	while (*pX != '\0')
	{
		if ((*pS == '\0') || (*pS != *pX))
		{
			doesContain = false;
			break;
		}

		++pS;
		++pX;
	}

	return doesContain;
}

char * findx(const char* s, const char* x)
{
	for (int i = 0; *(s+i) != '\0'; ++i)
	{
		if (strContains((s+i), x))
		{
			return const_cast<char*>(s+i);
		}
	}

	return NULL;
}

int main()
{
	char input[] = "ab asd we rew wer PEPI aaa OK OK";
	char searchTerm[] = "PEPI";
	char * occurence = findx(input, searchTerm);
	cout << occurence << endl;

	return 0;
}

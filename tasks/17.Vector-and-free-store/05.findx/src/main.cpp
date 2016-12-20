#include <iostream>

using namespace std;

bool strContains(const char* s, const char* x)
{
	bool doesContain = true;
	for (int i = 0; x[i] != '\0'; ++i)
	{
		if ((s[i] == '\0') || (s[i] != x[i]))
		{
			doesContain = false;
			break;
		}
	}

	return doesContain;
}

char * findx(const char* s, const char* x)
{
	for (int i = 0; s[i] != '\0'; ++i)
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

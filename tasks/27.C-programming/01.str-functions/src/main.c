#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

size_t m_strlen(const char * str)
{
	size_t cnt = 0;
	while (*str++) ++cnt;
	return cnt;
}

int m_strcmp(const char * str1, const char * str2)
{
	int result = 0;
	while (*str1 && *str2 && *str1 == *str2)
	{
		++str1;
		++str2;
	}

	if (*str1 < *str2)
	{
		result = 1;
	}
	else if (*str1 > *str2)
	{
		result = -1;
	}
	else
	{
		result = 0;
	}

	return result;
}

char *m_strcpy(char *dest, const char *src)
{
	char * start = dest;
	while (*src) *dest++ = *src++;
	return start;
}

int main()
{
	char * str1 = "Hello";
	size_t length = m_strlen(str1);
	printf("Size of %s is %d\n", str1, length);
	
	char * str2 = "Hello";
	char * str3 = "Hell";
	char * str4 = "Bello";
	char * str5 = "Iello";

	printf("strcmp: %s <-> %s --> %d\n", str1, str2, m_strcmp(str1, str2));
	printf("strcmp: %s <-> %s --> %d\n", str1, str3, m_strcmp(str1, str3));
	printf("strcmp: %s <-> %s --> %d\n", str1, str4, m_strcmp(str1, str4));
	printf("strcmp: %s <-> %s --> %d\n", str1, str5, m_strcmp(str1, str5));
	
	char buffer[20];
	m_strcpy(buffer, str1);
	printf("strcpy: %s --> %s\n", str1, buffer);
	
	return 0;
}

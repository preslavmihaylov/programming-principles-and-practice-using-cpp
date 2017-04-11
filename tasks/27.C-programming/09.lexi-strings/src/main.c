#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 200

int strComp(const void* first, const void* second)
{
	const char * ff = first;
	const char * ss = second;
	return -strcmp(ff, ss);
}

int main()
{
	char ** arr;
	int n;
	char * str;

	scanf("%d", &n);

	arr = malloc(sizeof(char*) * n);

	for (int cnt = 0; cnt < n; ++cnt)
	{
		str = malloc(sizeof(char) * MAX_SIZE);
		scanf("%s", str);
		arr[cnt] = str;
	}

	qsort(arr, n, sizeof(char*), strComp);

	for (int cnt = 0; cnt < n; ++cnt)
	{
		printf("%s ", arr[cnt]);
		free(arr[cnt]);
	}

	free(arr);

	return 0;
}

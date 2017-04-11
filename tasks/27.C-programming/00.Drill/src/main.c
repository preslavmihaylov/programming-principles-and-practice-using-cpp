#include <stdlib.h>
#include <stdio.h>

void printVars(char * p, int x)
{
	printf("p is \"%s\" and x is %d\n", p, x);
}

int main()
{
	char * hello = "Hello";
	char * world = "World";

	printf("%s, %s\n", hello, world);

	printVars("foo", 7);
	return 0;
}

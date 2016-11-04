#include "cust_randint.h"

#include <ctime>

unsigned int next = time(NULL);

void cust_srand(int seed)
{
    next = seed;
}

int cust_randint()
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

int cust_randInRange(int a, int b)
{
    return ((cust_randint() % (b - a)) + a);
}

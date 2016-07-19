#include "my.h"

#include <iostream>

int foo;

void print_foo()
{
    std::cout << "FOO: " << foo << std::endl;
}

void print(int i)
{
    std::cout << "I: " << i << std::endl;
}

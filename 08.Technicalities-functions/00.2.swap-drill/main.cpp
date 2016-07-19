#include <iostream>

using namespace std;

void swap_v(int first, int second)
{
    int temp;
    temp = first;
    first = second;
    second = temp;
}

void swap_r(int & first, int & second)
{
    int temp;
    temp = first;
    first = second;
    second = temp;
}

void swap_cr(const int & first, const int & second)
{
    // dummy code left in order for the compile not to perform optimizations
    int temp = first;
    temp = second;
    // Cannot modify const reference
    /*
    int temp;
    temp = first;
    first = second;
    second = temp;
    */
}

void test_swap_v()
{
    int x = 7;
    int y = 9;
    swap_v(x, y);
    swap_v(7, 9);
    const int cx = 7;
    const int cy = 9;
    swap_v(cx, cy);
    swap_v(7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_v(dx, dy);
    swap_v(dx, dy);

    std::cout << "TEST SWAP_V" << std::endl;
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
    std::cout << "CX: " << cx << std::endl;
    std::cout << "CY: " << cy << std::endl;
    std::cout << "DX: " << dx << std::endl;
    std::cout << "DY: " << dy << std::endl;
}

void test_swap_r()
{
    int x = 7;
    int y = 9;
    swap_r(x, y);
    // Cannot pass read-only constant to reference param
    //swap_r(7, 9);
    const int cx = 7;
    const int cy = 9;
    // Cannot pass read-only constant to reference param
    //swap_r(cx, cy);
    //swap_r(7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;
    // Cannot pass double as reference of different type
    //swap_r(dx, dy);
    //swap_r(dx, dy);

    std::cout << "TEST SWAP_R" << std::endl;
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
    std::cout << "CX: " << cx << std::endl;
    std::cout << "CY: " << cy << std::endl;
    std::cout << "DX: " << dx << std::endl;
    std::cout << "DY: " << dy << std::endl;
}

void test_swap_cr()
{
    int x = 7;
    int y = 9;
    swap_cr(x, y);
    swap_cr(7, 9);
    const int cx = 7;
    const int cy = 9;
    swap_cr(cx, cy);
    swap_cr(7.7, 9.9);
    double dx = 7.7;
    double dy = 9.9;

    // Compiles successfully --> double converts to int which is converted to const int &
    swap_cr(dx, dy);
    swap_cr(dx, dy);

    std::cout << "TEST SWAP_CR" << std::endl;
    std::cout << "X: " << x << std::endl;
    std::cout << "Y: " << y << std::endl;
    std::cout << "CX: " << cx << std::endl;
    std::cout << "CY: " << cy << std::endl;
    std::cout << "DX: " << dx << std::endl;
    std::cout << "DY: " << dy << std::endl;
}

int main()
{
    test_swap_v();
    test_swap_r();
    test_swap_cr();
    return 0;
}

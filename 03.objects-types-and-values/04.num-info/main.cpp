#include <iostream>
#include <limits>

using namespace std;

double getSmallest(double first, double second)
{
    return first > second ? second : first;
}

double getLargest(double first, double second)
{
    return first > second ? first : second;
}

double getSum(double first, double second)
{
    return first + second;
}

double getDifference(double first, double second)
{
    return first - second;
}

double getProduct(double first, double second)
{
    return first * second;
}

double getRatio(double first, double second)
{
    if (second != 0)
    {
        return (double)first / second;
    }
    else
    {
        return numeric_limits<double>::quiet_NaN();;
    }
}

void readInput(double * num1, double * num2)
{
    cin >> *num1 >> *num2;
}

int main()
{
    double num1;
    double num2;

    readInput(&num1, &num2);
    cout << "Smallest: " << getSmallest(num1, num2) << endl;
    cout << "Largest: " << getLargest(num1, num2) << endl;
    cout << "Sum: " << getSum(num1, num2) << endl;
    cout << "Difference: " << getDifference(num1, num2) << endl;
    cout << "Product: " << getProduct(num1, num2) << endl;
    cout << "Ratio: " << getRatio(num1, num2) << endl;


    return 0;
}



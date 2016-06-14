#include <iostream>
#include <stdexcept>

using namespace std;

double celsius_to_fahrenheit(double celsius)
{
    return (celsius * 1.8 + 32);
}

double fahrenheit_to_celsius(double fahrenheit)
{
    return ((fahrenheit - 32) / 1.8);
}

void test_celsius()
{
    double celsius;
    cout << "Enter celsius: ";
    cin >> celsius;

    try
    {
        double fahrenheit = celsius_to_fahrenheit(celsius);
        cout << celsius << " celsius = " << fahrenheit << " fahrenheit" << endl;
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }
}

void test_fahrenheit()
{
    double fahrenheit;
    cout << "Enter fahrenheit: ";
    cin >> fahrenheit;

    try
    {
        double celsius= fahrenheit_to_celsius(fahrenheit);
        cout << fahrenheit << " fahrenheit = " << celsius << " celsius" << endl;
    }
    catch (runtime_error e)
    {
        cout << e.what() << endl;
    }
}

int main()
{

    test_celsius();
    test_fahrenheit();
    return 0;
}

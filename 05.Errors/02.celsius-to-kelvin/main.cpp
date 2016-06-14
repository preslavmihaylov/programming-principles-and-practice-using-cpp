#include <iostream>
#include <stdexcept>

using namespace std;

double celsius_to_kelvin(double celsius)
{
    if (celsius < -273.15)
    {
        throw runtime_error("Temperature in celsius must be higher than -273.15");
    }

    double kelvin = celsius + 273.15;
    return kelvin;
}

double kelvin_to_celsius(double kelvin)
{
    if (kelvin < 0)
    {
        throw runtime_error("Temperature in kelvin must be higher than 0");
    }

    double celsius = kelvin - 273.15;
    return celsius;
}

void test_celsius()
{
    double celsius = 0;
    cout << "Input celsius: ";
    cin >> celsius;

    try
    {
        double kelvin = celsius_to_kelvin(celsius);
        cout << celsius << " celsius = " << kelvin << " kelvin" << endl;
    }
    catch (runtime_error e)
    {
        cerr << e.what() << endl;
    }
}

void test_kelvin()
{
    double kelvin = 0;
    cout << "Input kelvin: ";
    cin >> kelvin;

    try
    {
        double celsius = kelvin_to_celsius(kelvin);
        cout << kelvin << " kelvin = " << celsius << " celsius" << endl;
    }
    catch (runtime_error e)
    {
        cerr << e.what() << endl;
    }
}

int main()
{
    test_celsius();
    test_kelvin();

    return 0;
}

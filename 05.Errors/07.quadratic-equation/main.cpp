#include <iostream>
#include <stdexcept>
#include <math.h>

using namespace std;

void calc_quadr_equation(double a, double b, double c, double& x1, double& x2)
{
    double discriminant = (b * b) - (4 * a * c);

    if (discriminant < 0)
    {
        throw runtime_error("There are no real roots");
    }

    x1 = (-b + sqrt(discriminant)) / (2 * a);
    x2 = (-b - sqrt(discriminant)) / (2 * a);
}

int main()
{
    double a, b, c, x1, x2;
    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;
    calc_quadr_equation(a, b, c, x1, x2);

    cout << "Roots: " << x1 << ", " << x2 << endl;
    return 0;
}

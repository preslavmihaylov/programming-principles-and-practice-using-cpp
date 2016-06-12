#include <iostream>
#include <math.h>

using namespace std;

double x1;
double x2;

bool solve_quad_equation(double a, double b, double c)
{
    double discriminant = (b * b) - (4 * a * c);

    if (discriminant < 0)
    {
        return false;
    }

    discriminant = sqrt(discriminant);
    x1 = (-b + discriminant) / (2 * a);
    x2 = (-b - discriminant) / (2 * a);

    return true;
}

int main()
{
    double a, b, c;

    cout << "Enter a, b and c: ";
    cin >> a >> b >> c;

    if (solve_quad_equation(a, b, c))
    {
        cout << "Real roots: " << x1 << " " << x2 << endl;
    }
    else
    {
        cout << "No real roots" << endl;
    }

    return 0;
}

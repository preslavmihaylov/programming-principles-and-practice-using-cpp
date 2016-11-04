#include <iostream>
#include <climits>
#include <stdexcept>
#include <algorithm>
#include <vector>

using namespace std;

#define MIN(x,y) (((x) > (y)) ? (y) : (x))
#define MAX(x,y) (((x) > (y)) ? (x) : (y))
#define ABS(x) (((x) > 0) ? (x) : -(x))

#define CM_COEF (1.0/100)
#define M_COEF (1.0)
#define IN_COEF (2.54/100)
#define FT_COEF ((IN_COEF * 12))


double convert_m(double value, string unit)
{
    double result;

    if (unit == "cm")
    {
        result = value * CM_COEF;
    }
    else if (unit == "m")
    {
        result = value * M_COEF;
    }
    else if (unit == "in")
    {
        result = value * IN_COEF;
    }
    else if (unit == "ft")
    {
        result = value * FT_COEF;
    }
    else
    {
        throw invalid_argument("Invalid unit entered");
    }

    return result;
}

bool is_valid_unit(string unit)
{
    return unit == "cm" ||
           unit == "m" ||
           unit == "in" ||
           unit == "ft";
}

void print_values(vector<double> values)
{
    cout << "Values: ";
    for (int cnt = 0; cnt < values.size(); ++cnt)
    {
        cout << values[cnt] << " ";
    }

    cout << endl;
}

int main()
{
    double value;
    string unit;

    double max_value = INT_MIN;
    double min_value = INT_MAX;
    double sum = 0;
    int values_cnt = 0;
    vector<double> values;

    while (cin >> value)
    {
        cin >> unit;
        if (is_valid_unit(unit))
        {
            value = convert_m(value, unit);
        }
        else
        {
            cout << "Invalid unit" << endl;
            continue;
        }

        if (value > max_value)
        {
            cout << "The largest so far" << endl;
            max_value = value;
        }

        if (value < min_value)
        {
            cout << "The smallest so far" << endl;
            min_value = value;
        }

        sum += value;
        ++values_cnt;
        values.push_back(value);
    }

    cout << "Sum: " << sum << "m" << endl;
    cout << "Values count: " << values_cnt << endl;
    cout << "Largest number: " << max_value << "m" << endl;
    cout << "Smallest number: " << min_value << "m" << endl;

    sort(values.begin(), values.end());
    print_values(values);

    return 0;
}

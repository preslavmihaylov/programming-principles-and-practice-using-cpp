#include <iostream>
#include <stdexcept>

using namespace std;

void read_input(string * op, double * first, double * second)
{
    cin >> *op >> *first >> *second;
}

double perform_operation(string op, double first, double second)
{
    if (op == "+")
    {
        return first + second;
    }
    else if (op == "-")
    {
        return first - second;
    }
    else if (op == "*")
    {
        return first * second;
    }
    else if (op == "/")
    {
        return first / second;
    }
    else
    {
        throw invalid_argument("Invalid operator");
    }
}

int main()
{
    // operator
    string op;
    double first, second;
    read_input(&op, &first, &second);

    try
    {
        double result = perform_operation(op, first, second);
        cout << result << endl;
    }
    catch (invalid_argument e)
    {
        cout << e.what() << endl;
    }



    return 0;
}

#include <iostream>

using namespace std;

void read_input(int * pennies, int * nickels, int * dimes, int * quarters, int * half_dollars)
{
    cout << "How many pennies do you have? ";
    cin >> *pennies;

    cout << "How many nickels do you have? ";
    cin >> *nickels;

    cout << "How many dimes do you have? ";
    cin >> *dimes;

    cout << "How many quarters do you have? ";
    cin >> *quarters;

    cout << "How many half dollars do you have? ";
    cin >> *half_dollars;
}

void print_output(int pennies, int nickels, int dimes, int quarters, int half_dollars, double dollars)
{
    string pennies_out = "pennies";
    string nickels_out = "nickels";
    string dimes_out = "dimes";
    string quarters_out = "quarters";
    string half_dollars_out = "half dollars";

    if (pennies == 1)
    {
        pennies_out = "penny";
    }

    if (nickels == 1)
    {
        nickels_out = "nickel";
    }

    if (dimes == 1)
    {
        dimes_out = "dime";
    }

    if (quarters == 1)
    {
        quarters_out = "quarter";
    }

    if (half_dollars == 1)
    {
        half_dollars_out = "half dollar";
    }

    cout << "You have " << pennies << " " << pennies_out << endl;
    cout << "You have " << nickels << " " << nickels_out << endl;
    cout << "You have " << dimes << " " << dimes_out << endl;
    cout << "You have " << quarters << " " << quarters_out << endl;
    cout << "You have " << half_dollars << " " << half_dollars_out << endl;
    cout << "Total dollars: " << dollars << "$" << endl;
}

double calculate_dollars(int pennies, int nickels, int dimes, int quarters, int half_dollars)
{
    double pennies_coef = 0.01;
    double nickels_coef = 0.05;
    double dimes_coef = 0.10;
    double quarters_coef = 0.25;
    double half_dollars_coef = 0.5;

    return pennies * pennies_coef +
           nickels * nickels_coef +
           dimes * dimes_coef +
           quarters * quarters_coef +
           half_dollars * half_dollars_coef;
}

int main()
{
    int pennies, nickels, dimes, quarters, half_dollars;

    read_input(&pennies, &nickels, &dimes, &quarters, &half_dollars);
    double dollars = calculate_dollars(pennies, nickels, dimes, quarters, half_dollars);
    print_output(pennies, nickels, dimes, quarters, half_dollars, dollars);

    return 0;
}

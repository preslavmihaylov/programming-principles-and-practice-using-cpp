#include <iostream>
#include <cmath>

using namespace std;

#define MAXN 500

static int multiplier_count[MAXN];
typedef unsigned long long U64;

U64 cust_pow(U64 number, U64 power)
{
    if (power == 0)
    {
        return 1;
    }

    if (power % 2 == 0)
    {
        U64 curr_result = cust_pow(number, power / 2);
        return curr_result * curr_result;
    }
    else
    {
        return number * cust_pow(number, power - 1);
    }
}

void factorize(int start, int fin, int modifier)
{
    int cnt;
    for (cnt = start; cnt <= fin; ++cnt)
    {
        int multiplier = cnt;
        int prime = 2;
        while (multiplier > 1)
        {
            int modify_cnt = 0;
            while (multiplier % prime == 0)
            {
                multiplier /= prime;
                ++modify_cnt;
            }

            if (modify_cnt > 0)
            {
                multiplier_count[prime] += modify_cnt * modifier;
            }

            prime++;
        }
    }
}

void factorize_permutation(int n, int k)
{
    factorize(n - k + 1, n, 1);
}

void factorize_combination(int n, int k)
{
    factorize_permutation(n, k);
    factorize(1, k, -1);
}

U64 calculate_result()
{
    U64 result = 1;
    for (int cnt = 0; cnt < MAXN; ++cnt)
    {
        if (multiplier_count[cnt] > 0)
        {
            // occurences_count * current_number
            result *= cust_pow(cnt, multiplier_count[cnt]);
        }
    }

    return result;
}

int main()
{
    cout << "syntax: operation n k" << endl;

    string operation;
    int n, k;

    cin >> operation >> n >> k;

    if (cin.fail())
    {
        cerr << "Invalid input" << endl;
        return 1;
    }

    if (k > n)
    {
        cerr << "K cannot be greater than N" << endl;
        return 1;
    }

    if (operation == "permutation")
    {
        factorize_permutation(n, k);
    }
    else if (operation == "combination")
    {
        factorize_combination(n, k);
    }
    else
    {
        cerr << "Unsupported operation" << endl;
        return 1;
    }

    U64 result = calculate_result();
    cout << "Result: " << result << endl;

    return 0;
}

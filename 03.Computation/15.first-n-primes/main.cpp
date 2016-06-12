#include <iostream>
#include <vector>

using namespace std;

vector<int> primes;

bool is_prime(int number)
{
    for (int cnt = 0; cnt < primes.size() && primes[cnt] * primes[cnt] <= number; ++cnt)
    {
        if (number % primes[cnt] == 0)
        {
            return false;
        }
    }

    primes.push_back(number);
    return true;
}

int main()
{
    int n;
    int cnt = 2;
    cout << "Enter n: ";
    cin >> n;


    while (primes.size() < n)
    {
        if (is_prime(cnt))
        {
            cout << cnt << endl;
        }

        ++cnt;
    }

    return 0;
}

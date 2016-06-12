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
    int limit;
    cout << "Enter limit: ";
    cin >> limit;

    for (int cnt = 2; cnt <= limit; ++cnt)
    {
        if (is_prime(cnt))
        {
            cout << cnt << endl;
        }
    }

    return 0;
}

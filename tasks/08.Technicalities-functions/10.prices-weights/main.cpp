#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

void input(vector<double> & prices, vector<double> & weights)
{
    double price;
    double weight;

    while (cin >> price && cin >> weight)
    {
        prices.push_back(price);
        weights.push_back(weight);
    }
}

double computeIndex(vector<double> & prices, vector<double> & weights)
{
    if (prices.size() != weights.size())
    {
        assert(false);
    }

    double result = 0;

    for (int cnt = 0; cnt < prices.size(); ++cnt)
    {
        result += prices[cnt] * weights[cnt];
    }

    return result;
}

int main()
{
    vector<double> prices;
    vector<double> weights;
    input(prices, weights);
    double index = computeIndex(prices, weights);
    cout << index << endl;

    return 0;
}

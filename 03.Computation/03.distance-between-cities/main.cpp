#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// we assume the numbers are sorted
double get_median(vector<double> &numbers)
{
    if (numbers.size() % 2 == 1)
    {
        return numbers[numbers.size() / 2];
    }
    else
    {
        // average of middle two elements
        return (numbers[numbers.size() / 2] + numbers[numbers.size() / 2 - 1]) / 2;
    }
}

int main()
{
    double max_distance = INT_MIN;
    double min_distance = INT_MAX;
    double curr_distance;
    double mean_distance = 0;
    int distances_cnt = 0;

    while (cin >> curr_distance)
    {
        mean_distance += curr_distance;
        ++distances_cnt;

        if (curr_distance > max_distance)
        {
            max_distance = curr_distance;
        }

        if (curr_distance < min_distance)
        {
            min_distance = curr_distance;
        }
    }

    mean_distance /= distances_cnt;

    cout << "Max distance: " << max_distance << endl;
    cout << "Min distance: " << min_distance << endl;
    cout << "Mean distance: " << mean_distance << endl;

    return 0;
}

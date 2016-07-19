#include <iostream>
#include <vector>
#include <climits>

using namespace std;

typedef struct sVectorInfo
{
    int smallest;
    int largest;
    double mean;
    double median;
} tVectorInfo;

void print(const tVectorInfo & vectorInfo)
{
    cout << "Smallest: " << vectorInfo.smallest << endl;
    cout << "Largest: " << vectorInfo.largest << endl;
    cout << "Mean: " << vectorInfo.mean << endl;
    cout << "Median: " << vectorInfo.median << endl;
}

void input(vector<int> & numbers)
{
    int number;
    while (cin >> number)
    {
        numbers.push_back(number);
    }
}

void computeVectorInfo(const vector<int> & numbers, tVectorInfo & vectorInfo)
{
    int smallest = INT_MAX;
    int largest = INT_MIN;
    double mean = 0;
    double median;
    int middle;

    for (int cnt = 0; cnt < numbers.size(); ++cnt)
    {
        if (numbers[cnt] < smallest)
        {
            smallest = numbers[cnt];
        }

        if (numbers[cnt] > largest)
        {
            largest = numbers[cnt];
        }

        mean += numbers[cnt];
    }

    mean /= numbers.size();

    middle = numbers.size() / 2;
    if (numbers.size() % 2 == 0)
    {
        median = (numbers[middle] + numbers[middle - 1]) / 2.0;
    }
    else
    {
        median = numbers[middle];
    }

    vectorInfo.smallest = smallest;
    vectorInfo.largest = largest;
    vectorInfo.median = median;
    vectorInfo.mean = mean;
}

int main()
{
    vector<int> numbers;
    tVectorInfo vectorInfo;
    input(numbers);
    computeVectorInfo(numbers, vectorInfo);
    print(vectorInfo);

    return 0;
}

#include <iostream>
#include <vector>

using namespace std;

template<typename T, typename A>
void print(const vector<T, A> & collection)
{
    for (int cnt = 0; cnt < collection.size(); ++cnt)
    {
        cout << collection[cnt] << " ";
    }

    cout << endl;
}

void print_str(const vector<string> & nums)
{

}


void reverse_v1(vector<int> & first, vector<int> & second)
{
    int secondIndex = 0;
    second.resize(first.size());

    for (int firstIndex = first.size() - 1; firstIndex >= 0;)
    {
        second[secondIndex++] = first[firstIndex--];
    }
}

void reverse_v2(vector<int> & numbers)
{
    int start = 0;
    int fin = numbers.size() - 1;
    int temp;

    for (int cnt = 0; cnt < numbers.size() / 2; ++cnt)
    {
        temp = numbers[start + cnt];
        numbers[start + cnt] = numbers[fin - cnt];
        numbers[fin - cnt] = temp;
    }
}

void reverse_v3(vector<string> & collection)
{
    int start = 0;
    int fin = collection.size() - 1;
    string temp;

    for (int cnt = 0; cnt < collection.size() / 2; ++cnt)
    {
        temp = collection[start + cnt];
        collection[start + cnt] = collection[fin - cnt];
        collection[fin - cnt] = temp;
    }
}

int main()
{
    vector<int> first = { 1, 2, 3, 4, 5 };
    vector<int> second;
    vector<string> strings = { "first", "second", "third", "fourth" };

    reverse_v1(first, second);
    print(second);
    reverse_v2(first);
    print(first);
    reverse_v3(strings);
    print(strings);
    return 0;
}

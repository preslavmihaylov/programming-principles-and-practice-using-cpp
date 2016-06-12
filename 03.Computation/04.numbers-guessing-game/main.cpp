#include <iostream>

using namespace std;

int main()
{
    int left = 1;
    int right = 100;
    int mid;
    int result;
    string answer;

    while (right > left)
    {
        mid = left + (right - left) / 2;

        cout << "Is the number you are thinking of less than or equal to " << mid << "? (y/n)" << endl;

        cin >> answer;

        if (answer == "y")
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << "The number is: " << left << endl;

    return 0;
}

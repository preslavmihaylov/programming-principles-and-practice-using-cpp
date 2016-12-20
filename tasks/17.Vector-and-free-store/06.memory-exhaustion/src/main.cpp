#include <iostream>

using namespace std;

int main()
{
	
	long long cnt = 1;
	while (true)
	{
		char* a = new char[1024];
		*a = 50;
		cout << "Current allocated memory: " << cnt << "KB" << endl;
		++cnt;
	}

	return 0;
}

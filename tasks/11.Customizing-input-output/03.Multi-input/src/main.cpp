#include <iostream>
#include <iomanip>

using namespace std;

#define INPUT_CNT (3)

void RaiseError(string errorMsg)
{
	cout << errorMsg << '\n';
	exit(1);
}

int main()
{
	int num;
	char ch;
	cout << "Please enter " << INPUT_CNT << " integers "
			 "in hex,dec or oct form\n";

	// show '0x' and '0' infront of octal output
	cout << showbase;

	for (int index = 0; index < INPUT_CNT; ++index)
	{
		cin>>ch;
		
		if (ch == '0')
		{
			cin >> ch;
			if (ch == 'x') // hexadecimal
			{
				cin >> hex >> num;
				if (cin.fail())
				{
					RaiseError("Invalid number");		
				}
				cout << hex << num << "\thexadecimal\t";
			}
			else if (isdigit(ch)) // octal
			{
				cin.unget();
				cin >> oct >> num;
				if (cin.fail())
				{
					RaiseError("Invalid number");	
				}
				cout << oct << num << "\toctal\t\t";
			}
			else
			{
				RaiseError("Invalid number");		
			}
		}
		else if (isdigit(ch)) // decimal
		{
			cin.unget();
			cin >> dec >> num;
			if (cin.fail())
			{
				RaiseError("Invalid number");	
			}

			cout << dec << num << "\tdecimal\t\t";
		}
		else
		{
			RaiseError("Invalid number");		
		}
		
		cout << "converts to\t" << dec << num << "\tdecimal\n";
	}
	return 0;
	cin.unsetf(ios::dec);
	cin.unsetf(ios::oct);
	cin.unsetf(ios::hex);
	// cin >> a >> b >> c;
	
	//cout << a << "\tconverts to\t" << dec << a << "\tdecimal\n";
	//cout << b << "\tconverts to\t" << dec << b << "\tdecimal\n";
	//cout << c << "\tconverts to\t" << dec << c << "\tdecimal\n";
	return 0;
}

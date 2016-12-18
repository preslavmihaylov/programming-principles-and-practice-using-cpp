#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
	Person()
		: Person("", 0) {};
	Person(string name, int age) 
	{
		setName(name);
		setAge(age);
	};

	string name() const { return n; }
	int age() const { return a; }

	void setName(string name) { n = name; }
	void setAge(int age) { a = age; }
private:
	string n;
	int a;
};

ostream& operator<<(ostream& outputStream, const Person& p)
{
	outputStream << p.name() << " " << p.age();
	return outputStream;
}

istream& operator>>(istream& inputStream, Person& p)
{
	string name;
	int age;
	inputStream >> name >> age;
	if (age < 0)
	{
		inputStream.clear(ios::failbit);
	}
	else
	{
		p.setAge(age);
		p.setName(name);
	}

	return inputStream;
}

int main()
{
	Person p("Goofy", 63);
	cout << p << endl;
	Person p1;
	cin >> p1;
	cout << p1 << endl;
	
	return 0;
}

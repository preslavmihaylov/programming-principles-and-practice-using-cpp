#include <iostream>
#include <vector>

using namespace std;

template<class T, class U> 
struct Pair
{
	T key;
	U value;
	Pair(T key, U value)
		: key(key), value(value) {};
};

template<class T, class U>
class SymbolTable
{
private:
	vector<Pair<T, U>> table;
public:
	void add(T key, U value = U())
	{
		table.push_back(Pair<T, U>(key, value));
	}

	const U& operator[](T key) const
	{
		for (int i = 0; i < table.size(); ++i)
			if (table[i].key == key) return table[i].value;
		
		throw runtime_error("No such key exists");
	}

	U& operator[](T key)
	{
		for (int i = 0; i < table.size(); ++i)
			if (table[i].key == key) return table[i].value;
	
		throw runtime_error("No such key exists");
	}
};

int main()
{
	SymbolTable<string, int> t;
	
	t.add("pesho", 20);
	cout << t["pesho"] << endl;
	
	t["pesho"] = 30;
	cout << t["pesho"] << endl;
	cout << t["minka"] << endl;	
	return 0;
}

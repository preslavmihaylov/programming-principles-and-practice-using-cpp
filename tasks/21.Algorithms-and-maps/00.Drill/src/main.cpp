#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <list>
#include <map>
#include <numeric>

using namespace std;

#define ITEMS_CNT 10

struct Item
{
	string name;
	int iid;
	double value;

	Item()
		: Item("", -1, 0) {};
	Item(string name, int iid, double value)
		: name(name), iid(iid), value(value) {};
};

class LessThan
{
public:
	LessThan(double value)
		: value(value) {};

	bool operator()(double other) { return other < value; }
private:
	double value;
};

class ItemFinderByName
{
public:
	ItemFinderByName(const string& name)
		: name(name) {};

	bool operator()(const Item& item) { return item.name == name; }
private:
	string name;
};

class ItemFinderByValue
{
public:
	ItemFinderByValue(double value)
		: value(value) {};

	bool operator()(const Item& item) { return item.value == value; }
private:
	double value;
};

class ItemComparator
{
public:
	enum ComparatorMode
	{
		byName,
		byId,
		byValue
	};
	
	enum ComparatorOrder
	{
		Ascending,
		Descending
	};

	ItemComparator(ComparatorMode mode = byName, 
				   ComparatorOrder order = Ascending)
		: mode(mode), order(order) {};
	
	bool operator()(const Item& a, const Item& b)
	{
		if (order == Ascending)
		{
			if (mode == byName) return b.name > a.name;
			else if (mode == byId) return b.iid > a.iid;
			else if (mode == byValue) return b.value > a.value;
			else throw runtime_error("Invalid comparator value");
		}
		else
		{
			if (mode == byName) return b.name < a.name;
			else if (mode == byId) return b.iid < a.iid;
			else if (mode == byValue) return b.value < a.value;
			else throw runtime_error("Invalid comparator value");
		}
	}
private:
	ComparatorMode mode;
	ComparatorOrder order;
};

istream& operator>>(istream& is, Item& item)
{
	is >> item.name >> item.iid >> item.value;
	return is;
}

istream& operator>>(istream& is, pair<string, int>& p)
{
	is >> p.first >> p.second;
	return is;
}

ostream& operator<<(ostream& os, const Item& item)
{
	os << "ID: " << item.iid << ' ';
	os << "Name: " << item.name << ' ';
	os << "Value: " << item.value;

	return os;
}

void vectorDrill()
{
	vector<Item> vi;
	Item currentItem;
	ifstream inputStream("input.txt");

	cout << endl << endl << "Vector Drill" << endl << endl;
	for (int i = 0; i < ITEMS_CNT; ++i) 
	{
		inputStream >> currentItem;
		vi.push_back(currentItem);
	}

	// sort by name
	sort(vi.begin(), 
		 vi.end(), 
		 ItemComparator(ItemComparator::byName));
	
	cout << "Sorted by name" << endl;
	for (auto item : vi)
	{
		cout << item << endl;
	}
	
	// sort by id
	sort(vi.begin(), vi.end(), ItemComparator(ItemComparator::byId));
	
	cout << "Sorted by ID" << endl;
	for (auto item : vi)
	{
		cout << item << endl;
	}
	
	// sort by value desc
	sort(vi.begin(), 
		 vi.end(), 
		 ItemComparator(ItemComparator::byValue,
		 				ItemComparator::Descending));
	
	cout << "Sorted by Value Descending" << endl;
	for (auto item : vi)
	{
		cout << item << endl;
	}

	// insert items
	vi.push_back(Item("horse shoe", 99, 12.34));
	vi.push_back(Item("Canon S400", 9988, 499.95));
	
	// erase by name
	vector<Item>::iterator it = 
		find_if(vi.begin(), vi.end(), ItemFinderByName("hat"));
	vi.erase(it);
	// erase by value
	it = find_if(vi.begin(), vi.end(), ItemFinderByValue(10));
	vi.erase(it);
	
	cout << "After insertion and deletion" << endl;
	for (auto item : vi)
	{
		cout << item << endl;
	}
}

void listDrill()
{
	list<Item> li;
	Item currentItem;
	ifstream inputStream("input.txt");

	cout << endl << endl << "List Drill" << endl << endl;
	for (int i = 0; i < ITEMS_CNT; ++i) 
	{
		inputStream >> currentItem;
		li.push_back(currentItem);
	}

	// sort by name
	li.sort(ItemComparator(ItemComparator::byName));
	
	cout << "Sorted by name" << endl;
	for (auto item : li)
	{
		cout << item << endl;
	}
	
	// sort by id
	li.sort(ItemComparator(ItemComparator::byId));
	
	cout << "Sorted by ID" << endl;
	for (auto item : li)
	{
		cout << item << endl;
	}
	
	// sort by value desc
	li.sort(ItemComparator(ItemComparator::byValue,
		 				   ItemComparator::Descending));
	
	cout << "Sorted by Value Descending" << endl;
	for (auto item : li)
	{
		cout << item << endl;
	}

	// insert items
	li.push_back(Item("horse shoe", 99, 12.34));
	li.push_back(Item("Canon S400", 9988, 499.95));
	
	// erase by name
	list<Item>::iterator it = 
		find_if(li.begin(), li.end(), ItemFinderByName("hat"));
	li.erase(it);
	// erase by value
	it = find_if(li.begin(), li.end(), ItemFinderByValue(10));
	li.erase(it);
	
	cout << "After insertion and deletion" << endl;
	for (auto item : li)
	{
		cout << item << endl;
	}
}

void mapDrill()
{
	map<string,int> msi;
	msi["k0"] = 0;
	msi["k1"] = 1;
	msi["k2"] = 2;
	msi["k3"] = 3;
	msi["k4"] = 4;
	msi["k5"] = 5;
	msi["k6"] = 6;
	msi["k7"] = 7;
	msi["k8"] = 8;
	msi["k9"] = 9;

	cout << endl << endl << "Map Drill" << endl << endl;
	for (pair<string,int> kv : msi)
	{
		cout << "(" << kv.first << ", " << kv.second << ")" << endl;
	}

	msi.clear();

	pair<string, int> p;
	for (int i = 0; i < 10; ++i)
	{
		cin >> p;
		msi[p.first] = p.second;
	}
	
	cout << "Inserted from input" << endl;
	for (pair<string,int> kv : msi)
	{
		cout << "(" << kv.first << ", " << kv.second << ")" << endl;
	}

	// Sum integers
	int res = accumulate(msi.begin(), 
						 msi.end(),
						 0,
						 [] (int value, 
						 	 const std::map<string, int>::value_type& p)
							 { return value + p.second; }
						);
	cout << "Sum of integers: " << res << endl;

	// copy to mis
	map<int, string> mis;
	for (pair<string, int> kv : msi)
	{
		mis[kv.second] = kv.first;
	}

	cout << "Values in map<int, string>" << endl;
	for (pair<int, string> kv : mis)
	{
		cout << "(" << kv.first << ", " << kv.second << ")" << endl;
	}
}

void vectorDrill2()
{
	vector<double> vd;
	double d;
	fstream inputStream("vector-input.txt");
	while (inputStream >> d) vd.push_back(d);

	cout << endl << endl << "Vector Drill 2" << endl << endl;
	cout << "Output vd to cout" << endl;

	cout << "vd contents" << endl;
	for (int i = 0; i < vd.size(); ++i) cout << vd[i] << " ";
	cout << endl;

	vector<int> vi(16);
	copy(vd.begin(), vd.end(), vi.begin());
	
	cout << "(vd,vi) pairs" << endl;
	for (int i = 0; i < vd.size(); ++i) 
	{
		cout << '(' << vd[i] << ", " << vi[i] << ")\n";
	}

	cout << "vd elements sum: ";
	double vdSum = accumulate(vd.begin(), vd.end(), 0.0);
	double viSum = accumulate(vi.begin(), vi.end(), 0);
	cout << vdSum << endl;

	cout << "Sum vd - vi: " << (vdSum - viSum) << endl;

	reverse(vd.begin(), vd.end());
	cout << "vd reversed" << endl;
	for (int i = 0; i < vd.size(); ++i) cout << vd[i] << " ";
	cout << endl;

	double vdMean = vdSum / vd.size();
	cout << "vd mean: " << vdMean << endl;
	vector<double> vd2(16);

	copy_if(vd.begin(), 
			vd.end(), 
			vd2.begin(), 
			LessThan(vdMean));

	cout << "vd2 contents" << endl;
	for (int i = 0; i < vd2.size(); ++i) cout << vd2[i] << " ";
	cout << endl;

	sort(vd.begin(), vd.end());
	cout << "Sorted vd" << endl;
	for (int i = 0; i < vd.size(); ++i) cout << vd[i] << " ";
	cout << endl;
}

int main()
{
	vectorDrill();
	listDrill();
	mapDrill();
	vectorDrill2();

	return 0;
}

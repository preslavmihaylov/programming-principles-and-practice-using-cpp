#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <iterator>

using namespace std;

struct Purchase
{
	string name;
	double unitPrice;
	int count;

	Purchase()
		: Purchase("", 0, 0) {};
	Purchase(string name, double unitPrice, int count)
		: name(name), unitPrice(unitPrice), count(count) {};
};

struct Order
{
	string custName;
	string address;
	vector<Purchase> purchases;

	Order() 
		: Order("", "") {};

	Order(const string& custName, const string& address)
		: custName(custName), address(address) {};

	friend bool operator<(const Order& o1, const Order& o2)
	{
		return o1.custName < o2.custName;
	}
	
	friend bool operator>(const Order& o1, const Order& o2)
	{
		return o1.custName > o2.custName;
	}
};

ostream& operator<<(ostream& os, const Purchase& purchase)
{
	os << "(" 
	   << purchase.name 
	   << " " << purchase.unitPrice 
	   << " " << purchase.count 
	   << ")";

	return os;
}

ostream& operator<<(ostream& os, const Order& order)
{
	os << order.custName << " " << order.address << " ";

	os << "{";
	for (int i = 0; i < order.purchases.size(); ++i) 
	{
		os << order.purchases[i] << " ";
	}

	os << "}";

	return os;
}

istream& operator>>(istream& is, Purchase& purchase)
{
	char ch1, ch2;

	is >> ch1 
	   >> purchase.name 
	   >> purchase.unitPrice 
	   >> purchase.count 
	   >> ch2;

	if (is)
	{
		if (ch1 != '(' || ch2 != ')')
		{
			is.clear(ios_base::failbit);
		}
	}
	return is;
}

istream& operator>>(istream& is, Order& order)
{
	char ch;
	Purchase purchase;
	order.purchases.clear();

	is >> order.custName >> order.address >> ch;
	
	if (ch == '{')
	{
		while (is >> purchase)
		{
			order.purchases.push_back(purchase);
			is >> ch;
			if (ch == '}')
			{
				break;
			}
			else
			{
				is.putback(ch);
			}
		}
	}
	else
	{
		is.clear(ios_base::failbit);
	}

	return is;
}

struct OrdersByName
{
	bool operator()(const Order& a, const Order& b) 
	{ 
		return a.custName > b.custName; 
	}	
};

struct OrdersByAddress
{
	bool operator()(const Order& a, const Order& b) 
	{ 
		return a.address > b.address; 
	}	
};

int main()
{
	ifstream is1("input1.txt");
	ofstream os1("output1.txt");

	ifstream is2("input2.txt");
	ofstream os2("output2.txt");
	vector<Order> orders1;
	vector<Order> orders2;
	Order order;
		
	while (is1 >> order) 
	{
		orders1.push_back(order);
	}

	while (is2 >> order)
	{
		orders2.push_back(order);
	}

	sort(orders1.begin(), orders1.end(), OrdersByName());
	sort(orders2.begin(), orders2.end(), OrdersByAddress());

	for (int i = 0; i < orders1.size(); ++i) os1 << orders1[i] << endl;
	for (int i = 0; i < orders2.size(); ++i) os2 << orders2[i] << endl;

	ofstream osFinal("output.txt");
	ostream_iterator<Order> oo(osFinal, "\n");
	
	merge(orders1.begin(), 
		  orders1.end(), 
		  orders2.begin(), 
		  orders2.end(), 
		  oo);

	return 0;
}

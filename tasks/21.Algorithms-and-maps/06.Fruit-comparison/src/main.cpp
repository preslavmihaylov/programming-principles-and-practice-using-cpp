#include <iostream>
#include <set>

using namespace std;

struct Fruit
{
	string name;
	int count;
	double unitPrice;
	Fruit(string name, int count, double unitPrice)
		: name(name), count(count), unitPrice(unitPrice) {};
};

struct FruitOrder
{
	bool operator()(const Fruit* a, const Fruit* b) const
	{
		return (*a).name < (*b).name;
	}
};

int main()
{
	set<Fruit*, FruitOrder> inventory;
	inventory.insert(new Fruit("apple", 5, 5.5));
	inventory.insert(new Fruit("pineapple", 6, 9.9));
	inventory.insert(new Fruit("melon", 1, 7.3));
	inventory.insert(new Fruit("kiwi", 9, 3.5));
	inventory.insert(new Fruit("strawberry", 23, 1.5));
	
	for (auto fruit : inventory) cout << fruit->name << endl;

	return 0;
}

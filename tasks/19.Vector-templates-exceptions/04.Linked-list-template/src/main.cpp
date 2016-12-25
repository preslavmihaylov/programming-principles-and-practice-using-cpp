#include <iostream>
#include "linked_list.h"

using namespace std;

template<class T>
void printAll(Link<T>* l)
{
	Link<T>* current = l;
	while (current)
	{
		cout << current->getValue() << " ";
		current = current->getNext();
	}
	cout << '\n';
}

int main()
{
	Link<string>* norseGods = new Link<string>("Thor");
	norseGods = norseGods->insert(new Link<string>("Odin"));
	norseGods = norseGods->insert(new Link<string>("Zeus"));
	norseGods = norseGods->insert(new Link<string>("Freia"));

	Link<string>* greekGods = new Link<string>("Hera");
	greekGods = greekGods->insert(new Link<string>("Athena"));
	greekGods = greekGods->insert(new Link<string>("Mars"));
	greekGods = greekGods->insert(new Link<string>("Poseidon"));

	printAll(norseGods);
	printAll(greekGods);

	// Correct Mars to Ares
	Link<string> * p = greekGods->find("Mars");
	if (p) p->setValue("Ares");

	// Move Zeus to greek gods
	Link<string>* zeus = norseGods->find("Zeus");
	if (zeus)
	{
		if (zeus == norseGods) norseGods = norseGods->getNext();
		
		zeus->erase();
		greekGods = greekGods->insert(zeus);
	}
	
	printAll(norseGods);
	printAll(greekGods);
	return 0;
}

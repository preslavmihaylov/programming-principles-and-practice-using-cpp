#include <iostream>
#include "linked_list.h"

using namespace std;

void printAll(Link* l)
{
	Link* current = l;
	while (current)
	{
		cout << current->getValue() << " ";
		current = current->getNext();
	}
	cout << '\n';
}

int main()
{
	Link* norseGods = new Link("Thor");
	norseGods = norseGods->insert(new Link("Odin"));
	norseGods = norseGods->insert(new Link("Zeus"));
	norseGods = norseGods->insert(new Link("Freia"));

	Link* greekGods = new Link("Hera");
	greekGods = greekGods->insert(new Link("Athena"));
	greekGods = greekGods->insert(new Link("Mars"));
	greekGods = greekGods->insert(new Link("Poseidon"));

	printAll(norseGods);
	printAll(greekGods);

	// Correct Mars to Ares
	Link * p = greekGods->find("Mars");
	if (p) p->setValue("Ares");

	// Move Zeus to greek gods
	Link* zeus = norseGods->find("Zeus");
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
